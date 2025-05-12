#include "node.h"
#include <iostream>
using namespace std;


class SentinelDLL{

node* head;
node* tail;
int size;


void removeNode(node* temp){

    node* pred = temp->prev;
    node* succ = temp->next;


    pred->next = succ;
    succ->prev = pred;

    delete temp;

    size--;

}


node* addBetween(int num, node* pred, node* succ){

    node* newNode = new node;
    newNode->data = num;

    newNode->next = succ;
    newNode->prev = pred;

    pred->next = newNode;
    succ->prev = newNode;

    size++;


}

public : 
    SentinelDLL(){
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

public: 
    void addHead(int num){
        addBetween(num , head , head->next);
    }

    void addTail(int num){
        addBetween(num, tail->prev, tail);
    }

    void addAt(int num, int pos){
        node* current;
        
        if(pos <= size / 2 ){
            current = head->next;
            for(int i=0; i<pos && current !=tail; i++){
                current = current->next;
            }
            addBetween(num,current->prev,current);

        }else{
            current = tail->prev;
            for(int i=0; i<pos && current != head ; i++){
                current = current->prev;
            }
            addBetween(num,current,current->next);

        }
    }

    void print() {
        node* curr = head->next;
        while(curr != tail) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
    }

 
};