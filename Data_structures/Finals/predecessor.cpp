#include <iostream>
#include "BST.h"
using namespace std;



// Example usage and tests
int main() {
    BST tree;
    
    // Create test tree:
    /*
           10
          /  \
         5    15
        / \     \
       3   7     20
          /     /
         6     17
    */
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(20);
    tree.insert(6);
    tree.insert(17);
    
    // Run tests (value, expected_predecessor, expected_successor)
    tree.runTest(10, 7, 15);      // Middle node
    tree.runTest(5, 3, 6);        // Node with two children
    tree.runTest(3, -1, 5);       // Minimum value
    tree.runTest(20, 17, -1);     // Maximum value
    tree.runTest(7, 6, 10);       // Node with left child only
    tree.runTest(17, 15, 20);     // Node with no children
    tree.runTest(100, -1, -1);    // Non-existent value
    
    return 0;
}