



array[size++]=num;
int index = size -1;
int parent = (index-1)/2;

while(index > 0 && array[index]> array[parent]){
    swap;
    index = parent;
    parent= (index-1)/2;
}


remove max 

int index = size -1;
int parent = (index -1)/2;

int root=0;

int temp = array[root];
array[root]= array[index];
array[index]=temp;

int value = array[index];
size--;

while(true){
    int left = root* 2+1;
    right = root*2+2;
    largest = array[root]

    if(left<size && array[left]> array[largest]){
        largest = array[left];
    }
    if(right<size && array[right > array[largest]]){
        largest = array[right];
    }
    if(root == largest){
        break;
    }
    swap();
    root = largest;


}

return value;