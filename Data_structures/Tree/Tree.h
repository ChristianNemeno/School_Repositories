#include <iostream>
#include "node.h"
#include <queue>

using namespace std;

class BinaryTree{

    int size; 
    

    public:
   //implement
   //height and depth of a node
   //addRoot
   node* root;
    BinaryTree(){
        size=0;
        root = NULL;
    }

    node* left(node* n){
        node* p = n;
        if(p){
            return p->left;
        }else{
            return NULL;
        }
    }

    node* right(node* n){
        node* p = n;
        if(p){
            return p->right;
        }else{
            return NULL;
        }
    }
    
    node* sibling(node* n){
        if(!n){
            return NULL;
        }
        node* p = n->parent;
        if(p){
            if(n == p->left){
                return p->right;
            }else{
                return p->left;
            }
        }
        return nullptr;
    }


    node* addRoot(int num){
        if(!root){
            node* n = new node;
            n->elem = num; 
            n->left = nullptr;
            n->right = nullptr;
            root = n;
            size++;     
            return n;
        }
        throw logic_error("Already has root");
        
    }
    node* addLeft(node* p, int num){
        if (!p || p->left) throw logic_error("Left child already exists or parent is null");
            
            
            node* n = new node;
            n->elem = num; 
            n->left = nullptr;
            n->right = nullptr;
            n->parent = n;

            p->left = n;
            size++;
           return n;
        }
    

    node* addRight(node* p, int num){
        if (!p || p->right) throw logic_error("Right child already exists or parent is null");
            node* n = new node;
            n->elem = num; 
            n->left = nullptr;
            n->right = nullptr;
            n->parent = p;

            p->right = n;
            size++;
               return n;
        }
        
    

    int remove(node* n){
        // 
        node* p = n->parent;
        bool right = n->right != NULL;

        if(n->right && n->left){
            throw logic_error(to_string(n->elem));
        }

        if(n->right){

        }else if(n->left){

        }
    }
  



    void print(node* e){
        if(e == nullptr)return;

        cout << e->elem << " "; // data
        print(e->left);         // left
        print(e->right);        // right
        // dlr ldr lrd
    }

    void BFS(){
        BFS(root);
    }

    void BFS(node* n){
        
        queue<node *> levels;

        levels.push(n);

        while(!levels.empty()){
            node* curr = levels.front();
            levels.pop();

            cout << curr->elem << " ";

            if(curr->left){
                levels.push(curr->left);
            }
            if(curr->right){
                levels.push(curr->right);
            }


        }


    }
    // D L R
    void preorder(){
        preorder(root);
    }

    void preorder(node* n){
        if(n == nullptr)return;
        cout << n->elem << " ";
        if(n->left){
            preorder(n->left);
        }
        if(n->right){
            preorder(n->right);
        }
    }

    
    // L D R
    void inOrder(){
        inOrder(root);
    }

    void inOrder(node* n){
        if(n == nullptr)return;
        
        if(n->left){
            inOrder(n->left);
        }
        cout << n->elem << " ";
        if(n->right){
            inOrder(n->right);
        }
    }

    // L D R
    void postOrder(){
        postOrder(root);
    }

    void postOrder(node* n){
        if(n == nullptr)return;
        
        if(n->left){
            postOrder(n->left);
        }
        
        if(n->right){
            postOrder(n->right);
        }
        cout << n->elem << " ";
    }
};