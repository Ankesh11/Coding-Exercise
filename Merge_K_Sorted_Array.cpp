#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int i;
    int j;
};
void swap(Node &a, Node &b){
    Node temp = a;
    a = b;
    b = temp;
}
class min_heap{
    Node *heap;
    int size;
    int capacity;
public:
    min_heap(int cap){
        size=0;
        capacity = cap;
        heap = new Node[cap];
    }
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    min_heapify(int i){
        int l = left_child(i);
        int r = right_child(i);
        int smallest = i;
        if(l<size && heap[l].data<heap[smallest].data)
            smallest = l;
        if(r<size && heap[r].data<heap[smallest].data)
            smallest = r;
        if(smallest!=i){
            swap(heap[i], heap[smallest]);
            min_heapify(smallest);
        }
    }
    void insert(Node data){
        heap[size] = data;
        size++;
        int i=size-1;
        while(i>0 && heap[i].data<heap[parent(i)].data){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    Node get_min(){return heap[0];}
    void replace_root(Node root){
        heap[0]=root;
        min_heapify(0);
    }
};
int *merge_k_sorted_array(int arr[][4],int n,int k){
    int *output = new int[n*k];
    min_heap mh(k);
    for(int i=0;i<k;i++)
        mh.insert(Node{arr[i][0], i, 1});
    for(int i=0;i<n*k;i++){
        Node root = mh.get_min();
        output[i] = root.data;
        if(root.j < n){
            root.data = arr[root.i][root.j];
            root.j += 1;
        }
        else
            root.data=INT_MAX;
        mh.replace_root(root);
    }
    return output;
}
int main(){
    int arr[][4] =  {{1,3,5,7},
                     {2,4,6,8},
                     {0,9,10,11}};
    int k = sizeof(arr)/sizeof(arr[0]);
    int n=4;
    int *output = merge_k_sorted_array(arr, n, k);
    for(int i=0;i<n*k;i++)
        cout<<output[i]<<" ";
    return 0;
}
