#include <iostream>
#include "ArrayMaxHeap.h"
using namespace std;

class TestMaxHeap {
private:
    void printTestResult(string testName, bool passed) {
        cout << "Test: " << testName << " -> " << (passed ? "PASSED" : "FAILED") << endl;
    }

public:
    void runAllTests(ArrayMaxHeap* heap) {
        testInsertion(heap);
        testRemoveMax(heap);
        testResizing(heap);
        testEdgeCases(heap);
        testComplexOperations(heap);
    }

    void testInsertion(ArrayMaxHeap* heap) {
        cout << "\n=== Testing Insertion ===\n";
        
        // Test 1: Basic inser  tion order
        heap->insert(5);
        heap->insert(10);
        heap->insert(3);
        heap->print();
        // Should show: 10, 5, 3
        
        // Test 2: Insert larger element
        heap->insert(15);
        heap->print();
        // Should show: 15, 10, 3, 5
        
        // Clear heap for next test
        while(heap->removeMax() != -1);
    }

    void testRemoveMax(ArrayMaxHeap* heap) {
        cout << "\n=== Testing RemoveMax ===\n";
        
        // Setup heap
        heap->insert(20);
        heap->insert(15);
        heap->insert(10);
        heap->insert(5);
        heap->insert(8);
        
        cout << "Initial heap:" << endl;
        heap->print();
        
        // Test 1: Remove maximum element
        int max = heap->removeMax();
        cout << "Removed " << max << endl;
        heap->print();
        // Should show removal of 20
        
        // Test 2: Remove multiple elements
        cout << "Removed elements in order: ";
        for(int i = 0; i < 3; i++) {
            cout << heap->removeMax() << " ";
        }
        cout << endl;
        heap->print();
        // Should show elements removed in descending order
        
        // Clear heap
        while(heap->removeMax() != -1);
    }

    void testResizing(ArrayMaxHeap* heap) {
        cout << "\n=== Testing Resizing ===\n";
        
        // Test 1: Growing
        cout << "Testing growth:" << endl;
        for(int i = 1; i <= 8; i++) {
            heap->insert(i * 10);
            heap->print();
        }
        
        // Test 2: Shrinking
        cout << "Testing shrink:" << endl;
        for(int i = 0; i < 6; i++) {
            heap->removeMax();
            heap->print();
        }
        
        // Clear heap
        while(heap->removeMax() != -1);
    }

    void testEdgeCases(ArrayMaxHeap* heap) {
        cout << "\n=== Testing Edge Cases ===\n";
        
        // Test 1: Remove from empty heap
        cout << "Removing from empty heap: " << heap->removeMax() << endl;
        
        // Test 2: Insert single element and remove
        heap->insert(42);
        cout << "Inserted 42:" << endl;
        heap->print();
        cout << "Removed: " << heap->removeMax() << endl;
        heap->print();
        
        // Test 3: Insert same value multiple times
        heap->insert(7);
        heap->insert(7);
        heap->insert(7);
        cout << "After inserting three 7s:" << endl;
        heap->print();
        
        // Clear heap
        while(heap->removeMax() != -1);
    }

    void testComplexOperations(ArrayMaxHeap* heap) {
        cout << "\n=== Testing Complex Operations ===\n";
        
        // Test alternating insertions and removals
        int values[] = {30, 20, 40, 15, 25, 35, 10};
        cout << "Inserting and removing alternately:" << endl;
        
        for(int i = 0; i < 7; i++) {
            heap->insert(values[i]);
            cout << "After inserting " << values[i] << ":" << endl;
            heap->print();
            
            if(i % 2 == 1) {
                cout << "Removing max: " << heap->removeMax() << endl;
                heap->print();
            }
        }
        
        // Clear heap
        while(heap->removeMax() != -1);
    }
};

int main() {
    ArrayMaxHeap* heap = new ArrayMaxHeap();
    TestMaxHeap tester;
    tester.runAllTests(heap);
    //delete heap;  // Don't forget to free the memory
    return 0;
}