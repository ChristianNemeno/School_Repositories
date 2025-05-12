#include <iostream>

using namespace std;

int* Array; //Refactored kay samok ang squiqqly lines kay ambiguous ang "array" nga name, naa may array sa <tuple>
int n;
void print();
void sort_pivot(int, int);

int main(void) {
    // Hey there, start typing your C++ code here...
    cout << "Enter number of elements: ";
    cin >> n; 
    
    Array = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        cout << "Enter the element: " ;
        cin >> Array[i];

    }

    sort_pivot(0, n-1);
    cout << "finish";
    print();
    return 0;
}

void sort_pivot(int start, int end) {
    
    // Step 1: Identify pivot
    int pivot = start++;
    // Step 2: From after the pivot, go through the rest of the elements and print every swap
    for(int i = start ; i <= end; i++){
        if(Array[i] < Array[pivot]){
            
            swap(Array[i], Array[start]);
            start++;
            if(start != i){
                print();
            }
        }
    }
    
    
    // Step 3: Swap the pivot to the last green and print, if applicable
    if(pivot < start - 1){
        swap(Array[pivot], Array[start-1]);
        print();
    }
   

    // Step 4: Recursive call to the left partition, if applicable
    if(pivot < start - 2){
        cout << "Left partition of: " << Array[start-1] << endl;
        sort_pivot(pivot, start-2);
    }

    // Step 5: Recursive call to the right partition, if applicable
    if(start < end){
        cout << "Right partition of: " << Array[start-1] << endl;
        sort_pivot(start, end);
    }
}

void print() {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << Array[i];
        if (i < n-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}