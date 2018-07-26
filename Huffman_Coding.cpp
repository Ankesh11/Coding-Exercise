#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    int freq;
    Node *left;
    Node *right;
};
void swap(Node &a,Node &b){
    Node temp = a;
    a = b;
    b = temp;
}
class min_heap{
    Node **heap;
    int size;
    int capacity;
public:
    min_heap(int cap){
        capacity = cap;
        size = 0;
        heap = new Node*[capacity];
    }
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    void insert_key(Node *new_node){
        heap[size] = new_node;
        int i=size;
        size++;
        while(i>0 && heap[i]->freq<heap[parent(i)]->freq){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void min_heapify(int i){
        int l = left_child(i);
        int r = right_child(i);
        int smallest = i;
        if(l<size && heap[l]->freq<heap[smallest]->freq)
            smallest = l;
        if(r<size && heap[r]->freq<heap[smallest]->freq)
            smallest = r;
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            min_heapify(smallest);
        }
    }
    Node* extract_min(){
        Node *temp = heap[0];
        heap[0] = heap[size-1];
        size--;
        min_heapify(0);
        return temp;
    }
    int get_size(){return size;}
};
Node *create_node(char data, int freq){
    Node *temp = new Node();
    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *huffman_encoding(char data[], int freq[], int n){
    min_heap mh(n);
    for(int i=0;i<n;i++)
        mh.insert_key(create_node(data[i], freq[i]));
    while(mh.get_size()!=1){
        Node *left = mh.extract_min();
        Node *right = mh.extract_min();
        Node *new_node = create_node('#', left->freq+right->freq);
        new_node->left = left;
        new_node->right = right;
        mh.insert_key(new_node);
    }
    return mh.extract_min();
}
bool is_leaf(Node *node){
    return (node->left==NULL && node->right==NULL);
}
void print_codes_util(Node *root, int arr[], int index){
    if(root->left){
        arr[index] = 0;
        print_codes_util(root->left, arr, index+1);
    }
    if(root->right){
        arr[index] = 1;
        print_codes_util(root->right, arr, index+1);
    }
    if(is_leaf(root)){
        cout<<root->data<<" -> ";
        for(int i=0;i<index;i++)
            cout<<arr[i];
        cout<<endl;
    }
}
void print_codes(Node *root){
    int arr[100];
    int index;
    index=0;
    print_codes_util(root, arr, index);
}
int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(data)/sizeof(data[0]);
    Node *root = huffman_encoding(data, freq, n);
    print_codes(root);
    return 0;
}
