#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class ArrayMaxHeap{
    int* array;
    int size;
    int capacity = 5;

	int left(int n) {
        // TODO return the index of the left child of n
        return 2 * n + 1;
	}

	int right(int n) {
        return 2 * n + 2;
        // TODO return the index of the right child of n
	}

	void heapifyDown(int i){
		int l = left(i);
		int r = right(i);

	    int largest = i;

		if(l < size && array[l] > array[largest]){
			largest = l;
		}
		if(r < size && array[r] > array[largest]){
			largest = r;
		}
		if(largest != i){
			swap(i, largest);
			heapifyDown(largest);
		}

	}

	void swap(int index1, int index2){
	    int temp = array[index1];
	    array[index1] = array[index2];
	    array[index2] = temp;
	}

	void heapifyUp(int i){
	    int par = (i-1)/2;
		if(i != 0 && array[i] > array[par]){
			swap(i, par);
			heapifyUp(par);
		}
	}
	

    public:
    ArrayMaxHeap() {
    	// TODO perform memory allocation for array with capacity 50
    	array = (int*)malloc(5* sizeof(int));
    	size = 0;
	}
	
	

    // TODO insert the num into the heap
	void insert(int num) {
        if(size == capacity){
			capacity = ceil(capacity * 1.5);
			array = (int*)realloc(array, sizeof(int) * capacity);
		}

		array[size++] = num;
		heapifyUp(size-1);

	}
	
    // TODO remove the minimum value, -1 if empty
	int removeMax() {
		if (size == 0) return -1; // Return -1 if heap is empty
		int max = array[0];
		
		swap(0, size-1);
		
		size--;

		heapifyDown(0);
		if(size < capacity * 3.0 / 4.0){
			if(capacity > 5){
				capacity = ceil(capacity * 0.8);
				array = (int*)realloc(array, sizeof(int) * capacity);
			}else{
				capacity = 5;
			}
		}
		return max;
	}

    // DO NOT modify the code below
	void print() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
			cout << "Size: " << size << "/" << capacity << endl;
			cout << "TREE: " << endl;
			print_tree("", 0, false);

		cout << "ARRAY: ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void print_tree(string prefix, int n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
		if (left(n) < size) {
			print_tree(prefix + "|   ", left(n), true);
		}
		if (right(n) < size) {
			print_tree(prefix + "|   ", right(n), false);
		}
	}
};