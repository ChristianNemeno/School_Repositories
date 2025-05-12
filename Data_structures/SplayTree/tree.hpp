#include "node.hpp"
#include <iostream>
using namespace std;
class BSTree {
    node* root;
    int size;

    node* create_node(int num, node* parent) {
        node* n = (node*) malloc( sizeof(node) );
        n->element = num;
        n->parent = parent;
        n->right = NULL;
        n->left = NULL;
        return n;
    }

    bool search(node* curr, int num) {
        if (curr == NULL) {
            return false;
        }
        if (num == curr->element) {
            restructure(curr);
            return true ;
        }

        if (num < curr->element) {
            return search(curr->left, num);
        }
        return search(curr->right, num);
    }

    node* search_node(node* curr, int num) {
        if (!curr) return NULL;
        if (num == curr->element) {
            return curr;
        }
        if (num < curr->element) {
            if (curr->left != NULL) {
                return search_node(curr->left, num);
            }
            return curr;
        }
        if (curr->right != NULL) {
            return search_node(curr->right, num);
        }
        return curr;
    }
    

    public:
    BSTree() {
        root = NULL;
        size = 0;
    }

    bool search(int num) {
        return search(root, num);
    }

    bool insert(int num) {
        if (root == NULL) {
            root = create_node(num, NULL);
            size++;
            return true;
        } else {
            node* parent = search_node(root, num);
            if (parent->element != num) {
                node* newest = create_node(num, parent);
                if (parent->element < num) {
                    parent->right = newest;
                } else {
                    parent->left = newest;
                }
                size++;
                restructure(newest);
                return true;
            }
        }
        return false;
    }
    
    


    bool remove(int num){
    if(root == nullptr) return false;
    node* to_delete = search_node(root,num);
    if(to_delete->element != num) return false;
    
    if(to_delete != root)
        restructure(to_delete);

    node* left = to_delete->left;
    node* right = to_delete->right;

    if(left)
        left->parent = nullptr;
    
    if(right) 
        right->parent = nullptr;

    free(to_delete);
    size--;

    // naay rst
    if(right){
        root = right;
        node* successor = root;
        while(successor->left){
            successor = successor->left;
        }


        if(successor != root){
            restructure(successor);
        }
        
        root->left = left;
        if(left) left->parent = root;
        
        root->parent = nullptr;


    }else{
        root = left;
        if(root) 
            root->parent = nullptr;
    }
    return true;
}
    
    
    

    



    // TODO implementation of rotate operation of x where
    //  |
    //  y
    //   \
    //    x <- curr
    void zigleft(node* curr) {
        node* t2 = curr->left;
        node* par = curr->parent;
        if(!par){
            return;
        }
        
        node* gp = par->parent;
        
        if(gp){
            if(gp->right == par){
                gp->right = curr;
            }else{
                gp->left = curr;
            }
            curr->parent = gp;
            
        }
        
        curr->left = par;
        par->parent = curr;
        par->right = t2;
        if(t2){
            t2->parent = par;
        }
        if(!gp){
            root = curr;
            curr->parent = NULL;
        }
        
    }
    

    // TODO implementation of rotate operation of x where
    //   |
    //   y
    //  /
    // x <- curr
    void zigright(node* curr) {
        node* t2 = curr->right;
        node* par = curr->parent;
        if(!par){
            return;
        }
        
        node* gp = par->parent;
        
        if(gp){
            if(gp->right == par){
                gp->right = curr;
            }else{
                gp->left = curr;
            }
            curr->parent = gp;
            
        }
        
        curr->right = par;
        par->parent = curr;
        par->left = t2;
        if(t2){
            t2->parent = par;
        }
        if(!gp){
            root = curr;
            
            curr->parent = NULL;
        }
        

        
    }
    
    // GIVEN the child (or x), find the parent (or y), and the grandparent if any (or z).
    // Splay the child to the root recursively or iteratively.
    void restructure(node* child) {
        node* par; // parent
        // TODO find parent
        
        par = child->parent;
        // This is an indicator of the placement of parent to child (ptoc)
        bool ptoc_right = false;
        if (par->right == child) {
            ptoc_right = true;
        }
        
        node* gp = par->parent;
        // TODO find grandparent. If gp does not exist, proceed to doing ZIGLEFT or ZIGRIGHT.
        if(!gp){
            // either do zig left or zigright daw
            if(par->right == child){
                
                zigleft(child);
                cout << "ZIGLEFT" << endl;
            }else{
                zigright(child);
                cout << "ZIGRIGHT" << endl;
            }
            root = child;
            return;
        }
        // This is an indicator of the placement of grandparent to parent (gtop)
        bool gtop_right = false;
        if (gp->right == par) {
            gtop_right = true;
        }

        // FOR THE FOLLOWING: Write in each of the if statements a console output
        // on its corresponding operation (ZIGZIGLEFT, ZIGZIGRIGHT, ZIGZAGLEFT, or ZIGZAGRIGHT)

      // z
      //  \
      //   y
      //    \
      //     x
      if (gtop_right && ptoc_right) {
        // TODO call to either zigleft or zigright or both
        zigleft(par);
        zigleft(child);
        cout << "ZIGZIGLEFT" << endl;
        //root = child;
      }

      // z
      //   \
      //     y
      //    /
      //   x
      else if (gtop_right && !ptoc_right) {
        // TODO call to either zigleft or zigright or both
        zigright(child);
        zigleft(child);
        cout << "ZIGZAGLEFT" << endl;
        //root = child;
      }

      //     z
      //    /
      //   y
      //  /
      // x
      else if (!gtop_right && !ptoc_right) {
        // TODO call to either zigleft or zigright or both
        zigright(par);
        zigright(child);
        cout << "ZIGZIGRIGHT" << endl;
        //root = child;
        
      }

      //      z
      //    /
      //  y
      //   \
      //    x
      else {
        // TODO call to either zigleft or zigright or both
        zigleft(child);
        zigright(child);
        cout << "ZIGZAGRIGHT" << endl;
        // root = child;
      }


      root = child;
      if(child->parent){
        restructure(child);
      }
      return;
    }

    // WARNING. Do not modify the methods below.
    // Doing so will nullify your score for this activity.
    void print() {
        if (isEmpty()) {
            cout << "EMPTY" << endl;
            return;
        }
        cout << "PRE-ORDER: ";
        print_preorder(root);
        cout << endl << "IN-ORDER: ";
        print_inorder(root);
        cout << endl << "POST-ORDER: ";
        print_postorder(root);
        cout << endl << "STATUS: " << check_parent(root, NULL) << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print_preorder(node* curr) {
        cout << curr->element << " ";
        if (curr->left != NULL) {
            print_preorder(curr->left);
        }
        if (curr->right != NULL) {
            print_preorder(curr->right);
        }
    }

    void print_inorder(node* curr) {
        if (curr->left != NULL) {
            print_inorder(curr->left);
        }
        cout << curr->element << " ";
        if (curr->right != NULL) {
            print_inorder(curr->right);
        }
    }

    void print_postorder(node* curr) {
        if (curr->left != NULL) {
            print_postorder(curr->left);
        }
        if (curr->right != NULL) {
            print_postorder(curr->right);
        }
        cout << curr->element << " ";
    }

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->element << ": NULL -- must be " << par->element << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << "must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << " -- must be " << par->element << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};



