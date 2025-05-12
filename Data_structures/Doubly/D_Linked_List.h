#include <iostream>
#include "node.h"
#include "List.h"
using namespace std;

class DoublyLinkedList : public List{

    int size;
    node* head;
    node* tail;

    public:

    DoublyLinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    //utility
    int getSize(){
        return size;
    }

    void addHead(int num){
       if(head == nullptr){
        //means empty?
        node* n = (node*)calloc(1,sizeof(node));
        n->data = num;
        n->prev = nullptr;
        n->next = nullptr;

        head = n;
        size++;

        if(tail == nullptr){
            tail = head;
        }

        return;
       }

        // head is not null there exist more nodes

        node* n = (node*)calloc(1,sizeof(node));
        n->data = num;
        n->prev = nullptr;
        n->next = head;

        head->prev = n;

        head = n;
        size++;
    }

    void addTail(int num){
        
        if(tail == nullptr && head == nullptr){
            addHead(num);

            return;
        }
        //naay tail

        node* n = (node*)calloc(1,sizeof(node));
        //initialize the node
        n->prev = tail;
        n->data = num;
        n->next = nullptr;
        //link the tail to the new node 
        tail->next = n;
        // set new node as tail
        tail = n;
        size++;

        

    }

    void add(int num){
        addTail(num);
    }

    void addAt(int pos, int value){
        //empty
        if(!head){
            if(pos == 1){
                return addHead(value);
            }
        }
        if(pos == 1){
            return addHead(value);
        }
        node* curr = head;
        int i = 1;
        
        for(;i<pos;i++){
            curr = curr->next;
        }
        node* n = (node*)calloc(1,sizeof(node));
        
        //initialize the new node
        n->data = value;
        n->next = curr;
        n->prev = curr->prev;

        
        node* temp = curr->prev;

        temp->next = n;
        
        curr->prev = n;

        

        size++;



    }
    void addSorted(int num){
        //if empty
        if(!head){
            addHead(num);
            return;
        }
        if(head->data < num){
            addHead(num);
            return;
        }


        node* curr = head;
       
        while(curr){
            if(curr->data < num){
                break;                
            }
            
            curr = curr->next;
        }

        if(!curr){
            addTail(num);
            return;
        }

        node* n = (node*)calloc(1,sizeof(node));

        // initialize the node
        n->data = num;
        n->prev = curr->prev;
        n->next = curr;
        //
        curr->prev->next = n;
        //
        curr->prev = n;



    }

    int removeHead(){

        if(!head){
            cout << "Empty";
            return 0;
        }
        if(size == 1){
            size--;
            int temp = head->data;
            free(head);

            head =nullptr;
            tail=nullptr;
            return temp;
        }

        node* temp = head;
        int ret = temp -> data; 
        head = head->next;
        head->prev = nullptr;
        free(temp);
        size--;

        if(size == 0){
            head = nullptr;
            tail = nullptr;
        }

        return ret;

    }

    int removeTail(){
        if(!tail){
            return -1;
        }
        if(tail == head){
            return removeHead();
        }
        int ret = tail->data;
        node* temp = tail;
        tail = tail->prev;
        
        tail->next = nullptr;
        free(temp);
        size--;

        return ret;
    }

    int remove(int n){
        //single node;
        // handle head node , we cant really do a last node basin first occurence i remove if dups
        if(!head){
            cout << "Empty";
            return -1;
        }
        
        
        if(head->data == n){
            
            return removeHead();
        }
        
        node* curr = head;

        while( curr && curr->data != n  ){
            curr = curr->next;
        }
        //check if tail 
        if(!curr){
            
            return -1;
        }

        if(curr == tail){
            return removeTail();
        }

        int ret = curr->data;

        //link the prev and next first

        //i link ang previous node sa curr sa next node
    
        curr->prev->next = curr->next;

        // now si ang prev ni next node is ang prev sa curr
        curr->next->prev = curr->prev;

        // try it and pray
        free(curr);
        size--;

        return ret;
    }


    int removeAt(int pos){
        if(!head){

            return -1;
        }
        
        if(pos == 1){
            return removeHead();
        }

        if(pos == size){
            return removeTail();
        }

        int i = 1;
        node* curr = head;

        for(; curr && i<pos;i++){
            curr = curr->next;    
        }

        int ret = curr->data;

        //link the prev and next first

        //i link ang previous node sa curr sa next node
    
        curr->prev->next = curr->next;

        // now si ang prev ni next node is ang prev sa curr
        curr->next->prev = curr->prev;

        size--;
        // try it and pray
        free(curr);
        
        return ret;


    }

    int removeAll(int num){
        int ctr=0;
        while(head && head->data == num){
            int t = removeHead();
            ctr++;
        }
        node* curr = head;
        int hi=1;
        while(true){
            hi = remove(num);
            if(hi == -1){
                break;
            }
            ctr++;
        }
        return ctr;
    }


    int retain(int num){

        int ctr=0;
        
        while(head->data < num){
            
            head = head->next;
            head->prev = nullptr;
            size--;
            ctr++;
            if(size == 0){
                head = nullptr;
                tail = nullptr;
                return ctr;
            }
        }


        node* pred;
        node* succ;
        node* curr = head;
        while(curr){
            
            if(curr->data < num){
                if(curr == tail){
                    tail = tail->prev;
                    tail->next = nullptr;
                    size--;
                    if(size == 0){
                        head = nullptr;
                        tail = nullptr;
                    }
                    ctr++;
                    return ctr;
                }
                pred = curr->prev;
                succ = curr->next;
                
                pred->next = succ;
                succ->prev = pred;

                size--; 
                if(size == 0){
                    head=nullptr;
                    tail=nullptr;
                }
                ctr++;
            }
            curr = curr->next;

        }

        return ctr;
    }

    
    int corner(int left, int right) {
    
    if (left < 0 || right < 0 || left >= size || right >= size) {
        return -1;  // Error: invalid positions
    }



    int temp = size;
    size = left + right;

    int removed = temp -size;

   
    node* currentLeft = head;
    for (int i = 1; i < left; i++) {
        if(left == 0){
            break;
        }
        currentLeft = currentLeft->next;
    }

    // Traverse to the right position
    node* currentRight = tail;
    for (int j = 1; j < right; j++) {
        if(right == 0){
            break;
        }
        currentRight = currentRight->prev;
    }

    if(left == 0 && right == 0){
        head == nullptr;
        tail == nullptr;
        int t = size;
        size = 0;
        return t;
    }
    // If left == 0, adjust the head pointer
    if (left == 0) {
        head = currentRight;
        head->prev = nullptr;
        return right;
    }

    
    else if (right == 0) {
        tail = currentLeft;
        tail->next = nullptr;
        return left;
    }else{
        
    
    currentLeft->next = currentRight;
    currentRight->prev = currentLeft;
    }

    

    

    

    return removed; 
}
  

    void print(){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
        node* curr = head;
        while(curr){
            cout << curr->data << "->";
            
            curr = curr->next;
            
        }
        
        if(!curr){
            cout << "NULL" << endl;
        }
        cout << "Tail = " << tail->data << endl;
        cout << "Head = " << head->data << endl;

        cout <<endl;   
        return;
    }

    void print(node* param){
        node* curr = param;
        if(curr == head){
            print();
        }else if(param == tail){
            while(curr){
                curr = curr->prev;
            }
        }else{
            cout << "invalid node" << endl;
            return;
        }
        
        return;
    }
    int get(int pos){
        if(pos < 1 || pos > size){
            return -1;
        }
        int i;
        node* curr;
        int yeas;
        if(size / 2 <= pos){
            yeas = 1;
            curr = head;
            i=1;
            while(i<pos){
                curr=curr->next;
                i++;
            }
        }else{
            yeas =2;
            curr = tail;
            i=1;
            while(i < pos){
                curr=curr->prev;
                i++;
            }
        }

        if(yeas == 1){
            cout << "From head bro " << endl;
        }else{
            cout << "From tail bro " << endl;
        }

        return curr->data;
    }

    bool isEmpty(){
        return size == 0;
    }
    void combine(DoublyLinkedList* other){
        while(!other->isEmpty()){
            addTail(other->removeHead());
        }
    }




};


