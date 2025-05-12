#include <iostream>
#include "node.h"
#include "CircularList.h"

using namespace std;

int main() {
    LinkedList* list = new LinkedList();

    // Add elements to the list
    list->addFirst(10);
    list->addLast(20);
    list->addLast(30);
    list->addFirst(5);

    // Print the list
    cout << "List: ";
    list->print();  // Output should look like: 5 -> 10 -> 20 -> 30 ->

    return 0;
}