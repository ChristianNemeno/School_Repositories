#include <cstdlib>
#include <iostream>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = e;
		n->parent = parent;
		return n;
	}

	public:
	node* addRoot(int e) {
		if (root) {
			cout << "Root exists" << endl;
			return NULL;
		}
		node* n = create_node(e, NULL);
		root = n;
		size++;
		return n;
	}

	node* left(node* p) {
		return p->left;
	}

	node* right(node* p) {
		return p->right;
	}

	node* sibling(node* n) {
		node* par = n->parent;
		if (!par) {
			return NULL;
		}
		if (n == par->left) {
			return par->right;
		}
		return par->left;
	}

	node* addLeft(node* p, int e) {
		if (p->left) {
			cout << "Left of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->left = n;
		size++;
		return n;
	}

	node* addRight(node* p, int e) {
		if (p->right) {
			cout << "Right of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->right = n;
		size++;
		return n;
	}

    int remove(node* n) {
        int res = n->elem;
        if (left(n) && right(n)) {
            return -1;
        }
        if (!left(n) && !right(n)) {
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = NULL;
                } else {
                    par->right = NULL;
                }
            } else {
                root = NULL;
            }
        } else {
            node* child;
            if (left(n)) {
                child = left(n);
            } else {
                child = right(n);
            }
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = child;
                } else {
                    par->right = child;
                }
                child->parent = par;
            } else {
                root = child;
                child->parent = NULL;
            }
        }
        size--;
        free(n);
        return res;
    }

	node* getRoot() {
		return root;
	}

    // TODO copy your completed zigleft here
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
        par ->parent = curr;
        par->right = t2;
        if(t2){
            t2->parent = par;
        }
        if(!gp){
            root = curr;
            curr->parent = NULL;
        }
    }

    // TODO copy your completed zigright here
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
        par ->parent = curr;
        par->left = t2;
        if(t2){
            t2->parent = par;
        }
        if(!gp){
            root = curr;
            curr->parent = NULL;
        }
    }

	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root, false);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << n->elem << endl;
		if (n->left) {
			print_node(prefix + "|   ", n->left, true);
		}
		if (n->right) {
			print_node(prefix + "|   ", n->right, false);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->elem << ": NULL -- must be " << par->elem << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << "must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << " -- must be " << par->elem << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};