#include <iostream>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
    
};

class BST{
    node* root;

    node* insert(node* n, int key){
        // to do implement
        if(n == nullptr){
            return new node(key);
        }

        if(key < n->key){
            n->left = insert(n->left, key);
        }
        if(key > n->key){
            n->right = insert(n->right, key);
        }

        return n;

    }
    void inorder(node* n){
        if(n->left){
            inorder(n->left);
        }
        cout << n->key << " ";
        if(n->right){
            inorder(n->right);
        }
        
    }
    node* findMin(node* n){
        
        while(n && n->left != nullptr){
            n = n->left;
        }
        return n;
    }
    node* deleteNode(node* n, int key){
        if(n == nullptr){
            return n;
        }
        if(key < n->key){
            //lst
            n->left = deleteNode(n->left, key);
        }else if(key > n->key){
            //rst
            n->right = deleteNode(n->right, key);
        }else{
            //found
            if(n->left == nullptr){
                node* temp = n->right;
                delete n;
                return temp;
            }else if(n->right == nullptr){
                node* temp = n->left;
                delete n;
                return temp;
            }
            // may duha ka children
            node* temp = findMin(n->right);
            n->key = temp->key;

            n->right = deleteNode(n->right, temp->key);
        }
        return n;
    }

    public:
    BST(){
        root = nullptr;
    }

    void insert(int key){
        root = insert(root,key);
    }
    void inorder(){
        inorder(root);
    }
    void deleteNode(int key){
        deleteNode(root,key);
    }
    // complete binary tree
    int countNodes(node* n){
        if(n == nullptr) return 0;

        int LST = countNodes(n->left);
        int RST = countNodes(n->right);

        int complete = 0;
        if(n->left != nullptr && n->right != nullptr){
            complete = 1;
        }

        return LST + RST + complete;
    }

    






};