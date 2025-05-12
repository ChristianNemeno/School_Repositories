//#include "DynamicArrayList.h"
#include <iostream> 
#include "struct.h"
#include "ArrayStack.h"
using namespace std;
int main(){
    
     ArrayStack* stack = new ArrayStack;

    // Test isEmpty() on an empty stack
    cout << "Stack is empty: " << (stack->isEmpty() ? "true" : "false") << endl;
    // Expected output: true

    // Test push() and top()
    stack->push(10);
    stack->push(20);
    stack->push(30);
    cout << "Stack top element: " << stack->top() << endl;
    // Expected output: 30

    // Test size()
    cout << "Stack size: " << stack->size() << endl;
    // Expected output: 3

    // Test pop()
    cout << "Popped element: " << stack->pop() << endl;
    // Expected output: 30
    cout << "Popped element: " << stack->pop() << endl;
    // Expected output: 20

    // Test size() and top() after popping elements
    cout << "Stack size after pop: " << stack->size() << endl;
    // Expected output: 1
    cout << "Stack top element after pop: " << stack->top() << endl;
    // Expected output: 10

    // Test isEmpty() after some pops
    cout << "Stack is empty: " << (stack->isEmpty() ? "true" : "false") << endl;
    // Expected output: false

    // Test pop() until the stack is empty
    cout << "Popped element: " << stack->pop() << endl;
    // Expected output: 10
    cout << "Stack is empty: " << (stack->isEmpty() ? "true" : "false") << endl;
    // Expected output: true

    delete stack;  // Clean up memory
    return 0;
    
   
   

    
   
}

   
    
    // DynamicArrayList* list = new DynamicArrayList();
    
    // DynamicArrayList* anotherList = new DynamicArrayList();

    // anotherList->add(1);
    // anotherList->add(2);
    // anotherList->add(3);
    // anotherList->add(4);

    // char choice;
    // int value;

    // int pos;
    // int num;
    
    // do {
    //     cout << "\nMenu:\n";
    //     cout << "1. Add an element (a)\n";
    //     cout << "2. Print the list (p)\n";
    //     cout << "3. Remove and Element (r)\n";
    //     cout << "4. Exit\n";
    //     cout << "5. 1 for removeAll" << endl;
    //     cout << "6. 2 for batchInsert" << endl;
    //     cout << "Enter your choice: ";
    //     cin >> choice;



    //     switch (choice) {
    //         case 'a':
                
    //             cin >> value;
    //             list->add(value);
    //             break;

    //         case '@':
    //             cin >> pos;
    //             cin >> value;
    //             list->addAt(pos,value);

    //         break;

    //         case 'p':
    //             list->print();
    //             break;

    //         case 'x':
    //             std::cout << "Exiting the program.\n";
    //             break;

    //         case 'r': 
                
    //             cin >> value;
    //             list->remove(value);
    //             break;

    //         case '1':

    //             cin >> value;
    //             cout << "Number of elements removed: "<< list->removeAll(value) << endl;
    //         break;

    //         case '2':
    //             cin >> pos;
    //             cin >> num;
    //             list->batchInsert(pos,anotherList,num);

    //         break;

    //         default:
    //             std::cout << "Invalid choice. Please try again.\n";
    //     }
    // } while (choice != 'x');

    

   
