#include "List.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List{

int size;
Node* head;
Node* tail;


public:
LinkedList(){
     head = nullptr;
     tail = nullptr;
     size = 0;
}

void clear(){

     Node* curr = head;
     

     while(curr != nullptr){
          Node* temp = curr;
          curr = curr->next;
          delete temp;
     }
     tail=nullptr;
     size=0;
}



public:


// add methods here
     void insertBegin(int value){
          Node* node = (Node*)malloc(sizeof(Node));
          node->data = value;
          node->next = head;

          head = node;
          size++;

          if(!tail){
               tail = node;
          }
          cout << "Success" << endl;   
          
     }

     void insertLast(int value){
          if(!tail){
               insertBegin(value);
               return;
          }

          Node* node = (Node*)malloc(sizeof(Node));
          //
          node->data = value;
          node->next = nullptr;
          //

          tail->next = node;
          tail = node;
          size++;
          cout << "Success" << endl;

     }

     void add(int n){
          insertLast(n);
     }

     void addAt(int n, int index){
          if(index > size || index < 0){
               cout << "Out of bounds!";
               return;
          }
          if(index == 0){
               insertBegin(n);
               cout << "Success" << endl;
               return;
          }

          Node* curr = head;
          int i=0;
          while(i<index-1){
               curr = curr->next;
               i++;
          }
          Node* knew = (Node*)malloc(sizeof(Node));

          knew->data = n;
          knew->next = curr->next;
          curr->next = knew; 
          size++;
     }

     void addSorted(int num){

          //edge cases 
          //1. if list is empty
          //2. if added sa last
          // things to remember update size , tail and head

          Node* curr = head; 
          Node* prev = nullptr;
          while(curr){
               if(curr->data < num){

               }
          }
     }

//add methods ends here

// remove methods starts here
     int removeLast(){
          int ret = tail->data;
          if(!tail){
               cout << "Nope";
               return -1;
          }

          if(tail == head){
               
               free(tail);
               tail = nullptr;
               head = nullptr;
               // this is empty na
               size--;
               return ret;
          }
          Node* prevNode = head;
          while(prevNode->next != tail){
               prevNode = prevNode->next;     
          }
          free(tail);
          tail = prevNode;
          tail->next = nullptr;
          size--;
          if(isEmpty()){
               head = nullptr;
               tail = nullptr;
          }
          return ret;
     }

     int removeFirst(){
          if(!head){
               cout << "No nodes" << endl;
               return -1;
          }
          Node* temp; 
          temp = head;
          int ret = temp->data;
          head = head->next;
          temp->next = nullptr;
          free(temp);
          size--;
          if(isEmpty()){
               head = nullptr;
               tail = nullptr;
          }
          return ret;
     }

     int removeAt(int pos){

          if(pos == 1){
               int data = head->data;
               removeFirst();
               return data;
          }
          if(pos == size){
               return removeLast();
          }


          Node* curr = head;
          Node* prev;
          int i=1;
          while(i<pos && curr != nullptr){
               prev = curr;
               curr = curr->next;
               i++;
          }
          Node* temp = curr;
          int toRemove = temp->data;
          prev->next = curr->next;

          free(temp);
          size--;
          if(isEmpty()){
               head = nullptr;
               tail = nullptr;
          }

          return toRemove;
     }

     int remove(int n){
          int retu;
          if(!head){
               cout<< "no nodes";
               return 0;
          }
          if(tail->data == n){
               retu = removeLast();
               cout << "Success!" << endl;
               
               return retu;
          }
          if(head->data == n){
               retu = removeFirst();
               
               return retu;
          }
          

          Node* temp;
          Node* curr = head;
          while(curr){
               
               if(curr->next->data == n){
                    temp = curr->next;
                    retu = temp->data;
                    curr->next = curr->next->next;     
                    
               }
               curr = curr->next;
          }
          size--;
          if(isEmpty()){
               head = nullptr;
               tail = nullptr;
          }
          cout << "Success!" << endl;
          return retu;
     
     }

     int removeAll(int num){

          
          int ctr=0;
          while(head && head->data == num){
               Node* temp = head;
               head = head->next;
               free(temp);
               size--;
               ctr++;

          }
          if(!head){
               // empty
               head = nullptr;
               tail = nullptr;
               return ctr;
          }

          

          Node* curr = head;
          Node* prev=nullptr;
          while(curr){

               if(curr->data == num){
                    if(curr == tail){
                         Node* temp = curr;
                         prev->next = curr->next;
                         tail = prev;

                         free(curr);
                         size--;
                         ctr++;
                         return ctr;
                    }else{
                         Node* temp = curr;
                         prev->next = curr->next;
                         curr = curr->next;
                         free(temp);
                         size--; 
                         ctr++;
                    }
                    
               }else{
                    prev = curr;
                    curr = curr->next;  
               }

               


          }
          return ctr;
     }
     
     void print(){
          if(isEmpty()){
               cout << "Empty" << endl;
               return;
          }
          
          Node* curr = head;
          while(curr){
               cout << curr->data;
               if(curr->next != nullptr){
                    cout << "->";
               }
               curr = curr->next;

          }
          
          cout << endl;
     }
     int get(int pos){
          
          
          Node* curr = head;
          int i=0;
          while(i < pos){
               
               curr = curr->next;
               i++;
          }
          int temp = curr->data;    
          
          return temp;
     }
     
     int getSize(){
          return size;
     }
     
     bool isEmpty(){
          return size == 0;
     }

     void flip(){
          if (!head){
               return;
          }

          Node* current = head;
          tail = head;
          
          Node* prev = nullptr;
          Node* next = nullptr; 
          
          while(current != nullptr){
               
               next = current->next;

               current->next = prev;

               prev = current;

               current = next;
          }

          head = prev;



     }

};


