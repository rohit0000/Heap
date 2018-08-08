#include<iostream>
#define MAX 15
using namespace std;
struct node{
    int value_i;
    struct node *left_p;
    struct node *right_p;
    struct node *parent_p;
};


int size = 0;
class heap{
private:
    node *root_p;
    node* arr[MAX];
public:
    heap();
    int insert(int item_i);
    int remove(int item_i);
    int maximum();
    void levelOrder();
};

heap::heap(){
    size = 0;
    int i =0;
    for(; i < 15; i++){
        arr[i] = new node();
        arr[i]->value_i = 0;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int parent(int i){
    i = (i-1)/2;
    return i;
}

int leftChild(int i){
    return 2*i+1;
}
int rightChild(int i){
    return 2*i+2;
}

int heap::insert(int item_i){
    if(size == 0){
        root_p = arr[0];
        arr[0]->value_i = item_i;
        size++;
        return 0;
    }
    else if (size < MAX){
        arr[size]->value_i = item_i;
        size++;
        int i = size - 1;

        while (i != 0 && arr[parent(i)]->value_i < arr[i]->value_i)
        {
           swap(&arr[i]->value_i, &arr[parent(i)]->value_i);
           i = parent(i);
        }
    }

}
//void deleteNode(int i, int new_val)
//{
//    heap::arr[i]->value_i = new_val;
//    while (i != 0 && harr[parent(i)] > harr[i])
//    {
//       swap(&harr[i], &harr[parent(i)]);
//       i = parent(i);
//    }
//}

int heap::remove(int item_i){
    int left, right, i, temp, prevnode;

    for (i = 0; i < MAX; i++) {
        if (item_i == arr[i]->value_i)
            break;
    }
    if (item_i != arr[i]->value_i)
    {
        return -1;
    }
    arr[i]->value_i = arr[size - 1]->value_i;
    size = size - 1;
    prevnode =(i - 1) / 2;
    if (arr[i]->value_i > arr[prevnode]->value_i)
    {
        insert(arr[i]->value_i);
        return 0;
    }
    left = 2 * i + 1; /*left child of i*/
    right = 2 * i + 2; /* right child of i*/
    while (right < size)
    {
        if (arr[i]->value_i >= arr[left]->value_i && arr[i]->value_i >= arr[right]->value_i)
            return 0;
        if (arr[right]->value_i <= arr[left]->value_i)
        {
            temp = arr[i]->value_i;
            arr[i]->value_i = arr[left]->value_i;
            arr[left]->value_i = temp;
            i = left;
        }
        else
        {
            temp = arr[i]->value_i;
            arr[i]->value_i = arr[right]->value_i;
            arr[right]->value_i = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }/*End of while*/
    if (left == size - 1 && arr[i]->value_i)    {
        temp = arr[i]->value_i;
        arr[i]->value_i = arr[left]->value_i;
        arr[left]->value_i = temp;
    }
    return 0;
}

void heap::levelOrder(){
    int i;
    for (i=0; i < size; i++)
    {
        cout<< arr[i]->value_i << " ";
    }
}

int heap::maximum(){
    if(root_p != NULL)
        return root_p->value_i;
    return -1;
}

