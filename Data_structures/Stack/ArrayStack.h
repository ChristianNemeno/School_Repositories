#include "Stack.h"
#include "DynamicArrayList.h"


using namespace std;

class ArrayStack : public Stack{


DynamicArrayList* stacky;

public:
ArrayStack(){
    stacky = new DynamicArrayList;
}

void push(int num){
    stacky->addLast(num);
}

int pop(){
    return stacky->removeLast();
}
 
int top(){
    return stacky->get(size()-1);        
}

int size(){
    return stacky->_size();
}

bool isEmpty(){
    return stacky->isEmpty();
}


};