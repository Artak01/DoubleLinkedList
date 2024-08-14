#include <iostream>
#include "d_linked_list.h"

int main() {
    // Create a doubly linked list
    DLinkedList myList;

    // Add elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    // Display the list
    std::cout << "Original List: ";
    myList.display();
    std::cout << std::endl;

    // Access and modify elements
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // Insert an element at index 1
    myList.insert(1, 15);

    // Display the modified list
    std::cout << "Modified List: ";
    myList.display();
    std::cout << std::endl;

    // Remove an element
    myList.remove(20);

    // Display the list after removal
    std::cout << "List after removal: ";
    myList.display();
    std::cout << std::endl;

    // Splice another list into the current list
    DLinkedList anotherList;
    anotherList.push_back(30);
    anotherList.push_back(40);

    myList.splice(1, anotherList);

    // Display the list after splicing
    std::cout << "List after splicing: ";
    myList.display();
    std::cout << std::endl;

    return 0;
}

