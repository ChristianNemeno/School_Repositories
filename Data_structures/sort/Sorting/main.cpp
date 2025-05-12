#include <iostream>

#include "linkedlist.hpp"
#include "arraylist.hpp"

void bubbleSort(List*);
void selectionSort(List*);
void insertionSort(List*);
void quickSort(List* list);
void quickSortHelper(List* list , int low, int high);
int partition (List* list, int low , int high);
/**
 * This activity is focused on using Arrays and Linked Lists as two different
 * implementations of List. It follows that you are only to use the methods of
 * List and not of the specific array or linkedlist.
 */
int main(void) {
    // WARNING! Do not modify this line up until line 56!
    // Doing so will nullify your score for this activity.
    // Also, do not create more instances of ArrayList or LinkedList
    // aside from those in lines 24 and 26.
    char li;
    cout << "Enter type of list: ";
    cin >> li;

    List* list;
    if (li == 'A') {
      list = new ArrayList();
    } else {
      list = new LinkedList();
    }

    int length;
    cout << "Enter number of elements: ";
    cin >> length;

    int input;
    for (int i = 0; i < length; i++) {
      cout << "Enter element " << i+1 << ": ";
      cin >> input;
      list->add(input);
    }

    char sym;
    cout << "Enter sorting method: ";
    cin >> sym;
    list->print();
    switch (sym) {
      case 'B':
        bubbleSort(list);
        break;
      case 'I':
        insertionSort(list);
        break;
      case 'S':
        selectionSort(list);
        break;
      case 'Q':
        quickSort(list);
        break;
    }   
    return 0;
};

void quickSort(List* list){
    quickSortHelper(list, 0, list->size() - 1);
}

void quickSortHelper(List* list , int low, int high){
    if(low < high){
        
        int part = partition(list, low, high); 
        quickSortHelper(list,low, part - 1);
        quickSortHelper(list,part+1, high);

    }

}

int partition (List* list, int low , int high){
    int i = low - 1;

    int pivot = list->get(high);
    for(int j = low; j <= high-1; j++){
        if(list->get(j) < pivot){
            i++;
            list->swap(i, j);
            
        }
    }
    list->swap(i+1, high);
    list->print();
    return i+1;    
}

void bubbleSort(List* list) {
    
    int size = list->size(); // 2
    bool swapped;   
    for(int i = 0 ; i < size - 1; i++){ // 1 
        swapped = false; // 1
        for(int j = 0; j < size - i - 1; j++){ // 1 , 3n ,
            //cout << list->get(j); 
            // i assumed the add function would be used i used index to get lol
            if(list->get(j) > list->get(j+1)){ // 3n
                list->swap(j, j+1);
                list->print();
                swapped = true;
            }
        }
        if(!swapped) break; // 1 
    }

};

void selectionSort(List* list) {
    int size = list->size(); // 1 , 2
    int min;
    int i, j;
    for(i=0; i < size - 1; i++){ // 3 , 4n  
        min = i;
        // find minimum
        for(j = i + 1 ; j < size; ++j){
            if(list->get(j) < list->get(min)){ // n 
                min = j; // 1 
            }
        }
        
        if(min != i){
            list->swap(i,min); // n 
            list->print(); // n 
            
        }
        
    }
    

};

void insertionSort(List* list) {
    int size = list->size(); // 1
    int j; 
    int k;
    int kIdx;
    for(int i = 1 ; i < size; i ++){ // 1, n , n
        k = list->get(i); // n
        //kIdx = i;.
        j = i -1;
        while(j >= 0 && list->get(j) > k){ // 2n
            list->swap(j+1, j);
            list->print();
            j = j - 1; 
        }
    }
    
};