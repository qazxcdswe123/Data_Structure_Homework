//
// Created by yn on 21/9/2022.
//

#include "SinglyLinkedList.cpp"
#include <iostream>

int main()
{
    SinglyLinkedList<int> LL;
    bool a = LL.insertAfterPosition(0, 0);
    std::cout << a;
}