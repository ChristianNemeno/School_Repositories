#include "List.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class DynamicArrayList : public List {
private:
    int* array;
    int size;
    int capacity = 5;

    void dynamic_deduce_add(){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            array = (int*)realloc(array, sizeof(int) * capacity); 
        }
    }
    void dynamic_deduce_remove(){
        if(capacity > 5){
            if(size >= capacity * (3.0/4.0)){
            capacity = capacity - (capacity * .25);
            array = (int*)realloc(array, sizeof(int) * capacity); 
            }
        }   
    }
    


public:
    DynamicArrayList() : size(0) {
        array = (int*)malloc(capacity * sizeof(int));
    }


int get(int i){
    return array[i];
}

/*
options 

remove first and add Last

Remove last
add first

*/
int removeLast(){

    return array[--size];
}


void addFirst(int num){
    dynamic_deduce_add();
    for(int i=size; i>0; i--){
        array[i] = array[i-1];
    }
    array[0] = num;
    size++;
}

void addLast(int num){
    add(num);
    /*
     if(size == capacity){
        cout << "Resizing.. " << endl;
        capacity = ceil(capacity * 1.5);
        array = (int*)realloc(array,sizeof(int) * capacity);
    }   
    array[size++] = n;
    */
}

int removeFirst(){
    int t = array[0];
    for(int i=0; i < size-1; i++){
        array[i] = array[i+1];
    }
    size--;
    dynamic_deduce_remove();
    return t;
}

int _size(){
    return size;
}


void addAt(int pos, int value){
    if(size == capacity){
        cout << "Resizing.. " << endl;
        capacity =ceil(capacity * 1.5);

        array = (int*)realloc(array,sizeof(int) * capacity);
    }
    for(int i=size; i>=pos; i--){
        array[i] = array[i-1];
    }
    array[pos-1] = value;
    size++;
}

void add(int n){
    if(size == capacity){
        cout << "Resizing.. " << endl;
        capacity = ceil(capacity * 1.5);
        array = (int*)realloc(array,sizeof(int) * capacity);
    }   
    array[size++] = n;
}

int remove(int n){
    
    for(int i=0;i<size;i++){
        if(array[i] == n){
            for(int j=i; j<size-1;j++){
                array[j] = array[j+1];
            }
            size--;
            if(size <= capacity * (2.0/3.0)){
                if(capacity > 5){
                    cout << "Resizing.. " << endl;
                    capacity = capacity - floor(capacity * 0.25);
                    array = (int*)realloc(array,sizeof(int) * capacity);
                }
            }
            return i+1;
        }

    }

    
    return -1;
}

int removeAt(int pos){
    
    int temp = array[pos];

    for(int i=pos; i<size-1; i++){
        array[i] = array[i+1];
    }
    size--;
        if(size <= (capacity * (2.0/3.0))){
            if(capacity > 5){
                cout << "Resizing whahwoiahwfhaif" << endl;
                capacity = capacity - floor(capacity * 0.25);
                array = (int*)realloc(array,capacity * sizeof(int));
            }
    }    

    return temp;
}

int removeAll(int num){


    int ctr =0;

    while(1){
        int decision = remove(num);
        ctr++;
        if(decision == -1)break;

    }


    return ctr;
}

void combine(DynamicArrayList* list2){
    while(!list2->isEmpty()){
        int te = list2->removeAt(0);
        add(te);
    }
}

void removeRange(int start, int end){
    cout << endl;

    cout << "removed: ";
    for(int i = start; i < end; i++){
        int temp = removeAt(start);
        cout << temp << " ";   
    }
    cout << endl;
    
    
}

bool isEmpty(){
    return size == 0;
}

void print(){
    cout << size << "/"<< capacity << endl;
    for(int i=0; i<size;i++){
        cout << array[i] << " ";
    }
    cout << endl;

   
}


void batchInsert(int pos, DynamicArrayList* x, int numValues){
    int t = numValues;
    int what = pos;
    while(t != 0){

        addAt(what++, x->removeAt(0));    
        t--;

    }
}

};
