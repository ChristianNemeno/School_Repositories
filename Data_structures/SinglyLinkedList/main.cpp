#include <iostream>
#include "node.h"
#include "linked_list.h"
#include "List.h"

using namespace std;

int main(){

    LinkedList* list = new LinkedList();

    char choice;
    int value;
    int index;

    while(true){
        cout << "Enter choice : ";
        cin >> choice;
        //cin.ignore();

        switch(choice){
            case 'a': 
            
            //cout << "Enter value: ";
            cin >> value;
            list->add(value);

            break;

            case 'A':
            cout << "Value and Index please: ";
            cin >> value;
            cin >> index;
            list->addAt(value,index);
            break;

            case 'p':
            list->print();
            break;


            case 'R':
            //cout<< "Pos: ";
            cin >> value;
            list->removeAll(value);
            
            
            break;    

            case 'r':
            cin >> value;
            list->remove(value);
            break;

            case 'g':
            cin >> value;
            cout << list->get(value)<< endl;
            
            break;
            
            case 'x':
            return 0;
            break;

            case 'f':
            
            list->flip();
            cout << "Flipped!";
            break;

            

        }    

    }



    return 0;
}