#include <iostream>
#include "queue.h"
#include "DynamicArrayList.h"
using namespace std;


class ArrayQueue : public Queue{
     DynamicArrayList* list;
     
    public:
    ArrayQueue(){
        list = new DynamicArrayList();
    }


    void enqueue(int x){
        list->addLast(x);
        
    }
	int dequeue(){
        list->removeFirst();
    }
	int first(){
        if(size() == 0){
            return -1;
        }
        return list->get(0);
    }
	int size(){
        return list->_size();
    }
	bool isEmpty(){
        return size() == 0;
    }
	void print(){
        cout << "I dont know";
    }
};

/*
int first() returns the first

*/