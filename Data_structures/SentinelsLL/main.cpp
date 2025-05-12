#include <iostream>
#include "node.h"
#include "SentinelDLL.h"

using namespace std;

int main() {
    // Create an instance of SentinelDLL
    SentinelDLL* list = new SentinelDLL();

    // Add elements to the list
    int closer = list->addHead(5);
    cout << "Added 5. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;

    

    closer = list->addTail(10);
    cout << "Added 10. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;

    closer = list->addBetween(15, 4);
    cout << "Added 15. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;

    closer = list->addBetween(20, 2);
    cout << "Added 20. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;

    closer = list->addHead(12);
    cout << "Added 12. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;

    closer = list->addTail(6);
    cout << "Added 6. Closer to: " << (closer == 1 ? "Head" : "Tail") << endl;
    list->print();
    // Add more elements as needed and check their proximity to head or tail
    // This is just an initial test setup

    return 0;
}
