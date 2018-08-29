/*
 * MIT License
 * 
 * Copyright (c) 2018 Zach Wilder
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once
#ifndef LIST_HPP
#define LIST_HPP

namespace wsl
{

template <typename T>
class Node
{
    public:
        Node(T d) : data(d) { next = NULL; prev = NULL; }
         
        T data;
        Node * next; 
        Node * prev;
};

template <typename T>
class List
{
    public:
        List(); // Default constructor
        List(T data); // Alternate constructor
        List(const List<T> & other); // Copy constructor
        List<T> operator =(const List<T> & other) // Copy assignment using copy/swap idiom
        {
            swap(*this, other);
            return *this;
        }
        friend void swap(List<T> & first, List<T> & other)
        {
            List<T> * temp = first.head;
            first.head = other.head;
            other.head = temp;
        }
        ~List(); // Custom destructor
        
        
        void push(T data); // Add a node
        T pop(); // Remove head

        void remove(Node<T> * node); // Remove a node
        int size(); // Size (length) of list
        bool isEmpty();
        Node<T> * at(int index); // Node at specifc index

        Node<T> * head;
};

template <typename T>
List<T>::List()
{
    // Create an empty list
    head = NULL;
}   

template <typename T>
List<T>::List(T data)
{
    // Create a list, with T data
    push(data);
}   

template <typename T>
List<T>::List(const List<T> & other)
{
    // Copy constructor
    // Iterate through the other list, adding that list's data to this list
    for(Node<T> * node = other.head; node != NULL; node = node->next)
    {
        push(node->data);
    }
}

template <typename T>
List<T>::~List()
{
    Node<T> * node = head;
    Node<T> * next;
    
    while(node != NULL)
    {
        next = node->next;
        delete node;
        node = next;
    }
}; 

template <typename T>
void List<T>::push(T data)
{
    Node<T> * newNode = new Node<T>(data);
    if(head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

template <typename T>
T List<T>::pop()
{
    T result = T();
    if(head) // if head is NULL this returns false, same as 'head != NULL'
    {
        result = head->data; // Get result 
        remove(head);
        // Node<T> * temp = head; // Store a pointer to the current (old) list head
        // head = head->next; // Set the list head to the next item
        // head->prev = NULL; // The head has no previous node
        // delete temp; // Delete the old list head
    }
    return result;
}

// It's pretty common to want to remove a specific node from the list,
//  here's an idea of how that can be accomplished:
template <typename T>
void List<T>::remove(Node<T> * node)
{
    // If for some silly reason this function is called with NULL
    // this prevents an annoying segfault.
    if(!node) return; 
    if(!head) return; // If there's nothing in the list, we can't remove a node from it
    if(head == node)
    {
        // If we delete the head, we need to set the head to the next item in the list
        head = node->next;
        if(head) head->prev = NULL; // The head has no previous node
    }
    if(node->next != NULL)
    {
        // The next item's previous has to point to this item's previous 
        // Eg: A->B->C
        // Remove B, so C's previous has to be A
        node->next->prev = node->prev;
    }
    if(node->prev != NULL)
    {
        // The previous item's next has to point to this item's next
        // Eg:: A->B->C
        // Remove B, so A's next has to be C
        node->prev->next = node->next;
    }
    delete node;
}

// A few other common things that are pretty useful
//  and simple to implement:
// - Determining the size of a list
// - Determining if the list is empty
// - Getting a specific item from a list
template <typename T>
int List<T>::size()
{
    int result = 0;
    for(Node<T> * node = head; node != NULL; node = node->next)
    {
        result++;
    }
    return result;
}

template <typename T>
bool List<T>::isEmpty()
{
    return (head == NULL);
}

template <typename T>
Node<T> * List<T>::at(int index)
{
    Node<T> * result = NULL;
    
    int count = 0;
    for(Node<T> * node = head; node != NULL; node = node->next)
    {
        if(count == index)
        {
            result = node;
            break;
        }
        ++count;
    }
    return result;
}

} // Namespace wsl
#endif //LIST_HPP
