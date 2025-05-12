#include "list.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

// WARNING! Do not modify this struct!
// Doing so will nullify your score for this activity.
struct node {
    int element;
    node* next;
};

/**
 * This implementation is of a Singly-Linked List.
 * Feel free to add helper methods. You might want the create_node helper method.
 */
class LinkedList : public List {
    node* head;
    node* tail;
    int index;

    node* create_node(int num) {
        node* n = (node*)malloc(sizeof(node));
        n->element = num;
        n->next = NULL;
        
      return n;
    }

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            index = 0;
        }

        int add(int num) {
            
                node* n = create_node(num);
                if(head == nullptr){
                    head = n;
                    tail = n;
                }else{
                    //cout << to_string(n->element);
                    tail->next = n;
                    //cout << to_string(n->element);
                    tail = n;
                }
            
            
            index++;
            this->print();
          return index;
        }

        int get(int pos) { 
            if(pos > index || pos < 0){
                return -1;
            }
            
            node* curr = head;
            
            for(int i=0; i<pos; i++){
                curr = curr->next;
            }
            
            
          return curr->element;
        }

        int size() {
            return index;
        }
        
        void swap(int pos1, int pos2){
            node* node1 = head;
            node* prev1 = NULL;
            
            for(int i=0; i<pos1; i++){
                prev1 = node1;
                node1 = node1->next;
            }
            
            node* node2 = head;
            node* prev2 = NULL;
            
            for(int i=0; i<pos2; i++){
                prev2 = node2;
                node2 = node2->next;
            }
            
            if(prev1 != NULL){
                prev1->next = node2;
            } else{
                head = node2;
            }
            
            if(prev2 != NULL){
                prev2->next = node1;
            }else{
                head = node1;
            }
            
            if(node1 == tail){
                tail = node2;
            }else if(node2 == tail){
                tail = node1;
            }
            
            node* temp = node2->next;
            node2->next = node1->next;
            node1->next = temp;
            


        }
        

        void swap1(int pos1, int pos2) {
            // first initialize the node1 to head and prev to null
            node* node1 = head; 
            node* prev1 = NULL; 
            
            // then find node 1 and let its prev follow
            for(int i=0; i<pos1; i++){  
                prev1 = node1;
                node1 = node1->next;
            }

            //initialize the second node
            node* node2 = head; 
            node* prev2 = NULL; 
            
            // find second node to swap
            for(int i=0; i<pos2; i++){ 
                prev2 = node2;
                node2 = node2->next;
            }
            
            //this checks if prev 1 is null
            if(prev1 != NULL){ 
                prev1->next = node2;
            } else{
                head = node2;
            }

            
            if(prev2 != NULL){
                prev2->next = node1;
            }else{
                head = node1;
            }
            
            if(node1 == tail){
                tail = node2;
            }else if(node2 == tail){
                tail = node1;
            }
            
            node* temp = node2->next;
            node2->next = node1->next;
            node1->next = temp;
            

        }

        // WARNING! Do not modify this method below!
        // Doing so will nullify your score for this activity.
        void print() {
            node* currnode = head; 
            if (head == NULL && tail == NULL) { // 3
                cout << "(empty)"; 
                return;
            }
            while (true) { // 4
                cout << currnode->element; // 6 c + 3
                if (currnode == tail) {
                    cout << endl;
                    return;
                }
                cout << " -> ";
                currnode = currnode->next;
            }
        }
};