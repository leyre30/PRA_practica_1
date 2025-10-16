#include <iostream>
#include "ListArray.h"
#include "ListLinked.h"

int main() {
    ListArray<int> listArray;
    listArray.add(10);
    listArray.add(20);
    listArray.add(30);
    std::cout << "ListArray size: " << listArray.size() << std::endl;
    std::cout << "Element at index 1: " << listArray.get(1) << std::endl;

    ListLinked<int> listLinked;
    listLinked.add(100);
    listLinked.add(200);
    listLinked.add(300);
    std::cout << "ListLinked size: " << listLinked.size() << std::endl;
    std::cout << "Element at index 2: " << listLinked.get(2) << std::endl;

    return 0;
}

