#include <iostream>
using namespace std;

class BST {
private:
    struct node {
        int data;
        node* left;
        node* right;
        node* parent;
        
        node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    
    node* root;
    
    // Helper method to insert a new node
    node* insertHelper(node* current, int value, node* parent) {
        if (current == nullptr) {
            node* newnode = new node(value);
            newnode->parent = parent;
            return newnode;
        }
        
        if (value < current->data) {
            current->left = insertHelper(current->left, value, current);
        } else if (value > current->data) {
            current->right = insertHelper(current->right, value, current);
        }
        
        return current;
    }
    
    // Helper method to find a node
    node* findnode(int value) {
        node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return current;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }
    
    // Helper method to clean up memory
    void cleanupHelper(node* node) {
        if (node == nullptr) return;
        cleanupHelper(node->left);
        cleanupHelper(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    
    ~BST() {
        cleanupHelper(root);
    }
    
    void insert(int value) {
        root = insertHelper(root, value, nullptr);
    }

    node* findNode(int num){
        node* curr = root;
        node* target = nullptr;
        while(curr != nullptr){
            if(num == curr->data){
                target = curr;
                break;
            }else if(num < curr->data){
                curr = curr->left;
            }else if(num > curr->data){
                curr = curr->right;
            }
        }

        return target;
    }
    
    int predecessor(int value) {
       // find node;

       node* target = findNode(value);

        if(target == nullptr){
            return -1;
            }

       // 1st case if naay left
        if(target->left != nullptr){
            node* temp = target->left;
            while(temp->right != nullptr){
                temp = temp->right;
            } 
            

            return temp->data;
        }

        //2nd case if walay left
        node* ancestor = target->parent;
        node* child = target;

        while(ancestor != nullptr && ancestor->right == child){
            child = ancestor;
            ancestor = ancestor->parent;

        }

        if(ancestor == nullptr){return -1;}
 
        return ancestor->data;
    }
    
    int successor(int value) {
          // find node;

       node* target = findNode(value);

        if(target == nullptr){
            return -1;
            }

       // 1st case if naay left
        if(target->right != nullptr){
            node* temp = target->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }

            return temp->data;
        }

        //2nd case if walay left
        node* ancestor = target->parent;
        node* child = target;

        while(ancestor != nullptr && ancestor->left == child){
            child = ancestor;
            ancestor = ancestor->parent;

        }

        if(ancestor == nullptr){return -1;}
 
        return ancestor->data;
    }
    
    void runTest(int value, int expectedPred, int expectedSucc) {
        cout << "\nTesting for value: " << value << endl;
        
        // Test predecessor
        int predResult = predecessor(value);
        cout << "Predecessor test:" << endl;
        cout << "Expected: " << expectedPred << endl;
        cout << "Got: " << predResult << endl;
        cout << (predResult == expectedPred ? "PASSED" : "FAILED") << endl;
        
        // Test successor
        int succResult = successor(value);
        cout << "Successor test:" << endl;
        cout << "Expected: " << expectedSucc << endl;
        cout << "Got: " << succResult << endl;
        cout << (succResult == expectedSucc ? "PASSED" : "FAILED") << endl;
    }
};


//kdflkslkdflkdflkdflkdfoieroidfpij
//kjsdfkjdkjdfi2kdid
//dfijivciiiddd

//idjfijdfijdfijdfijdf2d9dvkj99jjJJKDNDNodvmimvifmvifvvfvi
///dfjdfijdfdf//dfdfducislnkcjs
//asdfghjklpopopopopoplljjj copkokpntenjent werker