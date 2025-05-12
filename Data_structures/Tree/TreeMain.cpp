#include <iostream>

#include "Tree.h"

using namespace std;

#include <stdexcept>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	  try {
        BinaryTree tree;

        // Add root
        node* root = tree.addRoot(10);
        cout << "Root added with value: " << root->elem << endl;

        // Add left and right children to root
        node* leftChild = tree.addLeft(root, 5);
        cout << "Left child added to root with value: " << leftChild->elem << endl;

        node* rightChild = tree.addRight(root, 15);
        cout << "Right child added to root with value: " << rightChild->elem << endl;

        // Add children to leftChild
        node* leftLeft = tree.addLeft(leftChild, 2);
        cout << "Left child added to left child with value: " << leftLeft->elem << endl;

        node* leftRight = tree.addRight(leftChild, 7);
        cout << "Right child added to left child with value: " << leftRight->elem << endl;

        // Display the tree in pre-order
        cout << "Tree elements in pre-order: ";
        tree.print(tree.root);
        cout << endl;

        // Check height of the tree
        //cout << "Height of the tree: " << tree.height(tree.root) << endl;

        // Check depth of various nodes
        // cout << "Depth of root: " << tree.depth(root) << endl;
        // cout << "Depth of left child (5): " << tree.depth(leftChild) << endl;
        // cout << "Depth of left-left child (2): " << tree.depth(leftLeft) << endl;

        // Check sibling of a node
        if (node* sibling = tree.sibling(leftChild)) {
            cout << "Sibling of left child (5) is: " << sibling->elem << endl;
        } else {
            cout << "Left child (5) has no sibling." << endl;
        }

    } catch (const logic_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
