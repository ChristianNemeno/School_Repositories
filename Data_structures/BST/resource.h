//   node* insert(node* n, int key){
//         if(n == nullptr){
//             return new node(key);
//         }

//         if(key < n->key){
//             //lefts subtree you go
//             n->left = insert(n->left, key);
//         }else if(key > n->key){
//             n->right = insert(n->right, key);
//         }


//         return n;
//     }

bool insert(int num){
    node* n = tree->getRoot();
    if(n == nullptr){
        tree->addRoot(num);
        return true;
    }
    return insert(n,num);
}



bool insert(node* n, int num){
    if(n == nullptr){
        return false;
    }

    if(n->elem == num){
        return false;
    }

    if(num < n->elem){
        if(!n->left){
            tree->addLeft(n, num);
            return true;
        }else{
            return insert(n->left, num);
        }

       
    }else{
         if(!n->right){
            tree->addRight(n, num);
            return true;
        }else{
            return insert(n->right, num);
        }
    }

}


bool search(int num){
    return search_node(tree->getRoot(), num);
}   



bool search(node* n, int num){
    if(n == nullptr){
        return false;
    }

    if(n->elem == num){
        return true;
    }else if(num < n->elem){
        return search(n->left, num);
    }else{
        return search(n->right, num);
    }


}

bool remove(int num){
    bool isRemoved = false;

    node* current = tree->getRoot();
    if()

    return isRemoved;

}


node* remove(node* node, int num, bool& isRemoved){
        if(node == nullptr){
            return n;
        }

        if(num < node->key){
            node->left = remove(node->left, num, isRemoved);
        }else if( num > node->key){
            node->right = remove(node->right, num, isRemoved);
        }else{
            //found
            if(node->left == nullptr){
                node* temp = node->right;
                delete node;
                isRemoved = true;
                return temp;  
            }
            if(node->right == nullptr){
                node* temp = node->left;
                delete node;
                isRemoved = true;
                return temp;
            }

            //two children
            node* t = findMin(n->right);
            int swap = t->key;
            node->key = swap;

            node->right = deleteNode(node->right, num, isRemoved);


        }
}

node* findMin(node* node){
    while(node != nullptr && node->left != nullptr){
        node = node->left;
    }
    return node;
}

// need root , smaller , div
bool checkPreOrder(int* arr, int start, int end){

    if(start >= end){
        return true;
    }
    int root = arr[start];
    int div = end;
    bool smaller = true;

    for(int i= start+1 ; i<=end; i++){
        if(smaller && arr[i] > root){
            div = i;
            smaller = false;

        }else if(smaller && arr[i] < root){
            return false;
        }
    }

    return checkPreOrder(arr, start +1, end -1) && checkPreOrder(arr, div, end);
}