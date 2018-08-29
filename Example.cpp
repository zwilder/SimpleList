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

#include <iostream>
#include "list.hpp"

int main(int argc, char * argv[])
{
    wsl::List<int> listA;

    std::cout << "Adding values (0,4,5) to list\n";
    listA.push(0);
    listA.push(4);
    listA.push(5);

    std::cout << "List Size before popping:" << listA.size() << std::endl;
    while(!listA.isEmpty())
    {
        std::cout << "Pop! " << listA.pop() << std::endl;
    }
    std::cout << "List Size after popping:" << listA.size() << std::endl;

    std::cout << "Adding values (1,3,4) to list\n";
    listA.push(1);
    listA.push(3);
    listA.push(4);

    std::cout << "List at [1]: " << listA.at(1)->data << std::endl;

    return 0;
}
