#include <iostream>
#include "D_Linked_List.h"
#include <limits> // for std::numeric_limits

using namespace std;

int main() {
    DoublyLinkedList* list = new DoublyLinkedList();
    DoublyLinkedList* list2 = new DoublyLinkedList();
    list2->add(1);
    list2->add(2);
    list2->add(3);
    list2->add(4);
    list2->add(5);
    int value;
    char choice;
    int pos;

    int l,r;

    while (true) {
        cout  << endl;
        cout << "[a] add" <<"\t\t"<<"[1] Remove All"<< endl;
        cout << "[A] addAt" <<"\t"<<"[2] addSorted"<<  endl;
        cout << "[r] remove" <<"\t" << "[c] corner"<< endl;
        cout << "[R] removeAt" << "\t" << "[3] retain"<<endl;
        cout << "[p] print" <<"\t" << "[4] size"<<endl;
        cout << "[x] exit" << "\t"<<"[5] get" <<endl;
        cout << "[z] combine" << "\t"<<"[y] list2 add" <<endl;

        cout  << endl;
        cout << "Enter choice: ";
        
            cin >> choice; 

         // Process choices
            switch (choice) {
                
                
                
                
                case 'c' : 
                cin >> l;
                cin >> r;
                cout << "Removed no. of removed elements: "<<list->corner(l,r);        
                
                break;


                case 'A':
                    cout << "Enter value to add and pos: ";
                    cin >> value;
                    cin >> pos;
                    // Validate input for value
                    
                    list->addAt(pos,value); // Assuming your add method is implemented
                    break;

                case 'a':
                    cin >> value;
                                                  
                    list->addTail(value); // Assuming your add method is implemented
                break;
                
                case 'r':
                    
                    cin >> value;

                    // Validate input for value
                    
                    cout << "Removed: " <<list->remove(value); // Assuming your remove method is implemented
                    break;

                case 'R':

                    cin >> pos;
                    cout <<"Removed: " <<list->removeAt(pos) << endl;

                    break;

                case '1':
                    cin>>value;
                    cout << "Number of removed instances: "<< list->removeAll(value) << endl;
                    break;

                case '2':
                    cin >> value;
                    list->addSorted(value);
                break;

                case '3':
                    cin >> value;
                    cout << "No. removed elements : "<<list->retain(value) << endl;
                break;

                case '4':
                    cout << "Current size of the list: "<<list->getSize() << endl;
                
                case '5':
                    cin >> pos;
                    cout << "Element at " << pos << " position "<<list->get(pos);
                break;

                case 'z':
                    list->combine(list2);
                    break;

                case 'y':
                    cin >> value;
                    list2->add(value);
                    break;

                case 'p':
                    list->print(); // Assuming your print method is implemented
                    list2->print();
                    break;
                case 'x':
                    delete list; // Clean up
                    return 0; // Exit the program
            }
    }
            // Clear input state and ignore the rest of the line
            

    return 0;
}
