
#include "queue.h"
#include <stdexcept>
class QueueArray : public Queue{
    int _size =0;
    int start = 0, end =0;
    int array[8];
    int cap = 8;

    public:
	void enqueue(int e){
        if(size() >= cap){
            //throw new exception();
            return;
        }
        if(end == cap ){
            end =0;
        }
        array[end++] = e;
        _size++;
    } 
	int dequeue(){
        start++;
        _size--;
        if(start == cap){
            start = 1;
        }
        int tmp =  array[start-1];
        if(start == cap){
            start =0;
        }
        return tmp;
    } 
	int first(){
        
    } 
	int size(){

    }
	bool isEmpty(){

    } 
	void print(){


    }
};
