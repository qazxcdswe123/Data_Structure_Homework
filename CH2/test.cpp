//
// Created by yn on 21/9/2022.
//

#include "LinkedList.cpp"
#include <iostream>

int main()
{
    LinkedList<int> LL;
    bool a = LL.insertAfterPosition(0, 0);
    std::cout << a;
}