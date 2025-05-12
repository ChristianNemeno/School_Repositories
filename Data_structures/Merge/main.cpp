#include <iostream>
#include "linkedlist.h"
#include <bits/stdc++.h>

LinkedList* mergeSort(LinkedList*);

// WARNING! Do not modify this main function!
// Doing so will nullify your score for this activity.
int main(void) {
    LinkedList* list = new LinkedList();

    int length;
    cout << "Input length: ";
    cin >> length;

    int input;
    for (int i = 0; i < length; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> input;
        list->add(input);
    }
    list->print();

    list = mergeSort(list);
    return 0;
};

node* split(LinkedList* list){
    node* slow = list->head;
    node* fast = list->head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return !fast ? slow : slow->next;

}


LinkedList* mergeSort(LinkedList* list) {
    // BASE CASE: When the list only contains one element.
    if(list->size() <= 1){
        return list;
    }
    // Step 1 - DIVIDE
    LinkedList* firsthalf = new LinkedList();
    LinkedList* secondhalf = new LinkedList();

    node* curr = list->head;

    node* middle = split(list);

    for(; curr != middle; curr = curr->next){
        firsthalf->add(curr->element);
    }
    
    for(; curr ; curr = curr->next){
        secondhalf->add(curr->element);
    }

    // Given: Step 2 - RECURSIVE CALL
    firsthalf->print();
    firsthalf = mergeSort(firsthalf);
    secondhalf->print();    
    secondhalf = mergeSort(secondhalf);

    // Step 3 - COMBINE
    
    LinkedList* sorted = new LinkedList();

    node* currfirst = firsthalf->head;
    node* currsecond = secondhalf->head;

    while(currfirst && currsecond){
        if(currfirst->element < currsecond->element){
            sorted->add(currfirst->element);
            currfirst = currfirst->next;
        }else{
            sorted->add(currsecond->element);
            currsecond = currsecond->next;         
        }
    }

    while(currfirst){
        sorted->add(currfirst->element);
        currfirst= currfirst->next;
    }
    while(currsecond){
        sorted->add(currsecond->element);
        currsecond= currsecond->next;
    }


    // print and return the sorted list
    sorted->print();
    return sorted;    
}