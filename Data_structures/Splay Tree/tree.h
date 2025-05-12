#include "node.h"
#include <iostream>
#include <cstdlib>
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
            return true;
        }

        if (num < curr->element) {
            return search(curr->left, num);
        }
        return search(curr->right, num);
    }

    node* search_node(node* curr, int num) {
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





    bool remove(int num) { // naka depende ang implementation sa unsay pama agi sa imong restructure,
      if (isEmpty()) {     //  in this case kay ga recursive call ko maong naay "if (rem_node != root)" sa pag call sa restructure mao rato bye
        return false;
      }
      node* rem_node = search_node(root, num);
      if (rem_node->element != num) {
        return false;
      }
      
      if (rem_node != root){
      	restructure(rem_node);
	  }
      
      
      node* left_subtree = root->left;
      node* right_subtree = root->right;
      
      if (left_subtree){
      	left_subtree->parent = NULL;
	  }
	  if (right_subtree){
      	right_subtree->parent = NULL;
	  }
      
      free(root);
      
      
      
      if (right_subtree){
      	root = right_subtree;
      	node* left_most = right_subtree;
      	while (left_most->left){
      		left_most = left_most->left;
		}
		
		
		if (left_most != root){
			restructure(left_most);
		}
		
		root->left = left_subtree;
		
		if (left_subtree){
			left_subtree->parent = root;
		}
		
		root->parent = NULL;
      	
      	
	  } else {
	  	root = left_subtree;
	  	if (root){
	  		root->parent = NULL;
		}
	  }
      
      size--;
      return true;
    }

    // TODO implementation of rotate operation of x where
    //  |
    //  y
    //   \
    //    x <- curr
    void zigleft(node* curr) {
        node* p = curr->parent;
        node* subtree = curr->left;
        
        curr->parent = p->parent;
        if (p->parent){
            if (p == p->parent->left){
                p->parent->left = curr;
            } else {
                p->parent->right = curr;
            }
        }
        
        curr->left = p;
        p->parent = curr;
        p->right = subtree;
        
        if (subtree) subtree->parent = p;
    }

    // TODO implementation of rotate operation of x where
    //   |
    //   y
    //  /
    // x <- curr
    void zigright(node* curr) {
        node* p = curr->parent;
        node* subtree = curr->right;
        
        curr->parent = p->parent;
        if (p->parent){
            if (p == p->parent->left){
                p->parent->left = curr;
            } else {
                p->parent->right = curr;
            }
        }
        
        curr->right = p;
        p->parent = curr;
        p->left = subtree;
        
        if (subtree) subtree->parent = p;
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

        node* gp;
        // TODO find grandparent. If gp does not exist, proceed to doing ZIGLEFT or ZIGRIGHT.
        gp = par->parent;
        // This is an indicator of the placement of grandparent to parent (gtop)
        bool gtop_right = false;
        if (gp){
            if (gp->right == par) {
                gtop_right = true;
            }
        }
        

        // FOR THE FOLLOWING: Write in each of the if statements a console output
        // on its corresponding operation (ZIGZIGLEFT, ZIGZIGRIGHT, ZIGZAGLEFT, or ZIGZAGRIGHT)
        
        if (!gp){
            if (ptoc_right){
                cout << "ZIGLEFT" << endl;
                zigleft(child);
            } else {
                cout << "ZIGRIGHT" << endl;
                zigright(child);
            }
            root = child;
            return;
        }
        
      // z
      //  \
      //   y
      //    \
      //     x
      if (gtop_right && ptoc_right) {
        // TODO call to either zigleft or zigright or both
        cout << "ZIGZIGLEFT" << endl;
        zigleft(par);
        zigleft(child);
        root = child;
      }

      // z
      //   \
      //     y
      //    /
      //   x
      else if (gtop_right && !ptoc_right) {
        // TODO call to either zigleft or zigright or both
        cout << "ZIGZAGLEFT" << endl;
        zigright(child);
        zigleft(child);
        root = child;
      }

      //     z
      //    /
      //   y
      //  /
      // x
      else if (!gtop_right && !ptoc_right) {
        // TODO call to either zigleft or zigright or both
        cout << "ZIGZIGRIGHT" << endl;
        zigright(par);
        zigright(child);
        root = child;
      }

      //      z
      //    /
      //  y
      //   \
      //    x
      else {
        // TODO call to either zigleft or zigright or both
        cout << "ZIGZAGRIGHT" << endl;
        zigleft(child);
        zigright(child);
        root = child;
      }
      
      if (root->parent){
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
                cout << "Illegal parent of " << curr->element << ": NULL -- must be " << par->element << endl; // modified the par->elem to par->element because it generates an error
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
