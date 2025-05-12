
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList{

int size;
node* head;
node* tail;


public:
LinkedList(){
     head = nullptr;
     tail = nullptr;
     size = 0;
}

public:

// add methods here 
void addFirst(int value){
    node* n = new node;
    if(!head){
        n->data = value;
        
        head = n;
        tail = n;
        n->next = head;
        
    }else{
        n->data = value;
        n->next = head;
        head=n;
        tail->next = n;
        
    }

    size++;

    return;


}

void addLast(int value){
    node* n = new node;
    if(!head){
        n->data = value;
        
        head = n;
        tail = n;
        n->next = head;

    }else{
        n->data = value;
        n->next = head;
        
        tail->next = n;
        tail = n;

    }

    size++;
    return;
}

void print(){
    if(head == nullptr){
        cout << "Empty" << endl;
        return;
    }

    node* curr = head;
    
    do{
        cout << curr->data << "->";
        curr = curr->next;
    }while(curr != head);



}
void rotate(int k){
    


}

int remove(int value){
    int ret;
    if(!head){
        return -1;
    }

    if(head == tail && head->data == value){
         ret = head->data;
        delete head; 
        head = nullptr;
        tail = nullptr;
        size =0;
        return ret;

    }

    if(head->data == value){
        node* temp = head;
        ret = head->data;
        head = head->next;
        tail->next = head;

        delete temp;

        size--;
        return ret;
    }

   
    node* curr = head; 
    node* previous = nullptr;
    do{
        previous = curr;
        curr = curr->next;
        

        if(curr->data == value){
            ret = curr->data;
            node* temp = curr;
            previous->next = curr->next;
            
            if(curr == tail){
                tail= previous;
            }
            
            delete temp;
            size--;
            return ret;
        }

        

    }while(curr != tail);


    return -1;
}
    

};