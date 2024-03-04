#include <iostream>
#include "double_list.h"

int main() {

    d_list myDoublyList;

    myDoublyList.push_back(10);
    myDoublyList.push_front(5);
    myDoublyList.push_back(20);

    std::cout << "Original List: ";
    myDoublyList.display();
    std::cout << std::endl;

    std::cout << "Front Element: " << myDoublyList.front() << std::endl;
    std::cout << "Back Element: " << myDoublyList.back() << std::endl;

    myDoublyList.remove(10);
    std::cout << "Updated List: ";
    myDoublyList.display();
    std::cout << std::endl;

    myDoublyList.insert(1, 15);
    std::cout << "Final List: ";
    myDoublyList.display();
    std::cout << std::endl;

    return 0;
}

