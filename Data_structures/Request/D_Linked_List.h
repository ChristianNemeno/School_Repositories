#include <iostream>
#include "node.h"
#include "List.h"
using namespace std;

class DoublyLinkedList{

    int size;
    node* head;
    node* tail;
    node* senior;
    public:

    DoublyLinkedList(){
        size = 0;
        head = new node; 
        tail = new node;
        head->next = tail;
        tail->prev = head;
        senior = head;
    }
    //utility
    int getSize(){
        return size;
    }
    //add last
    node* addBetween(Person* p, node* pred, node* succ){
         
        
        node* n = new node;
        n->person = p;
        n->prev = pred;
        n->next = succ;

        pred->next = n;
        succ->prev = n;
        size++;

        return n;
    }

    void add(Person* p){
       
      addBetween(p , tail->prev, tail);


    }

    Person* serveRequest(char ch){

        int index;
        switch (ch){
            case 'B' : 
            index = 0;
            break;

            case 'M' : 
            index = 1;
            break;

            case 'C':
            index = 2;
            break;

            case 'D':
            index = 3;
            break;
        }

        node* curr = head->next;

        Person* reference = NULL;

        while(curr != tail){
            
            if(curr->person->requests[index] == 1){
                curr->person->requests[index] = 0;
                reference = curr->person;

                // if no more request
                if( reference->requests[0] == 0 &&
                    reference->requests[1] == 0 &&
                    reference->requests[2] == 0 &&
                    reference->requests[3] == 0 ){

                        removeBetween(curr);

                    }
                
                break;
            }
            curr = curr->next;

        }

        return reference;
        
    }

    Person* fastLane(){

        Person* reference = nullptr;
        node* curr = head->next;

        while(curr != tail){

            if(curr->person->req_count() == 1){
                reference = curr->person;

                removeBetween(curr);
                break;
            }

            curr = curr->next;
        }
        return reference;
    }

    void removeBetween(node* n){
        // initialize the pred and succ
        if(size == 0){
            cout << "Empty";
            return;
        }
        node* pred = n->prev;
        node* succ = n->next;

        // link the pred and succ

        pred->next = succ;
        succ->prev = pred;

        free(n);
        size--;

    }

    void print(){
        node* curr = head->next;
        cout << "COUNTER : " << size << endl;
        if(size ==0 ){
            return;
        }

        cout << "FROM FIRST: " << endl;
        int ctr = 1; 
        while(curr != tail){
            cout << ctr++ << ". ";
            curr->person->print();

            curr = curr->next;

        }

        cout << "FROM LAST: " << endl;
        curr = curr->prev;
        while(curr != head){
            cout << --ctr << ". ";
            curr->person->print();
            curr = curr->prev;
        }



    }

    node* find_person(string name){

        node* curr = head->next;

        while(curr != tail->prev){
            if(curr->person->firstName == name || curr->person->lastName == name){
                break;
            }

            curr=curr->next;
        }

        return curr;
    }

    void advance(string name , int forward){
        node * target = find_person(name);

        node* pred = target->prev;
        node* succ = target->next;

        pred->next = succ;
        succ->prev = pred;

        node* position = target;
        for(int i=0; i<forward && position != head->next; i++){
            position = position->prev;
        }
            //setting pred and succ
            pred = position->prev;
            succ = position;
            //setting target links 
            target->prev = pred;
            target->next = succ;

            // connect to target
            pred->next = target;
            succ->prev = target;
           
    }

    void delay(string name, int delay){

        node* target = find_person(name);

        

        node* pred = target->prev;
        node* succ = target->next;

        pred->next = succ;
        succ->prev = pred;

        node* position = target;

        for(int i=0;  position != tail->prev && i<delay  ; i++){
            
            position = position->next;
        }
       

        pred = position;
        succ = position->next;

        target->prev = pred;
        target->next = succ;

        pred->next = target;
        succ->prev = target; 


    }

    void trade(string name1, string name2){
        
        node* target1 = find_person(name1);
        node* target2 = find_person(name2);

        if(target1->next == target2){
            // we insert target 2 behind target 1
            node* pred1 = target1->prev;
            node* succ1 = target1->next;
            
            node* pred2 = target2->prev;
            node* succ2 = target2->next; 

            
           

            target2->next = target1;
            target2->prev = pred1;

            pred1->next = target2;
            target1->prev = target2;



            // deal with target1

            succ2->prev = target1;
            target1->next = succ2;
            target1->prev = target2;
            target2->next = target1;
            



            return;
        }

        if(target1->prev == target2){
            node* pred1 = target1->prev;
            node* succ1 = target1->next;
            
            node* pred2 = target2->prev;
            node* succ2 = target2->next; 


            target1->next = nullptr;
            target1->prev = nullptr;

            target2->next = nullptr;
            target2->prev = nullptr;

            target1->next = target2;
            target1->prev = pred2;

            pred2->next = target1;
            target2->prev = target1;

            // target2

            target2->prev = target1;
            target2->next = succ1;

            succ1->prev = target2;


           
            return;
        }


        node* pred1 = target1->prev;
        node* succ1 = target1->next;

        
        node* pred2 = target2->prev;
        node* succ2 = target2->next; 

        // for t2
        target2->next = succ1;
        target2->prev =pred1;

        pred1->next = target2;
        succ1->prev = target2;

        target1->next = succ2;
        target1->prev = pred2;

        succ2->prev = target1;
        pred2->next = target1;

        


    }

};


