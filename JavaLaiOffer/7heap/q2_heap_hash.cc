/*
PriorityQueue + HashMap.

data structure, support median(), insert(), remove() operation.
O(logn)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
class HashHeap{
private:
    int size;
    vector<T> v;
    unordered_map<T, int> mapping;
public:
    HashHeap(){ }
    HashHeap(vector<T>);
    void BuildHeap();
    void Heapify(int);
    void Swap(T &, T&);

    T top(){
        return v[0];
    }

    bool empty(){
        return size == 0;
    }
    
    //remove top element
    void pop(){
        T t = v[0];
        Swap(v[0], v[size-1]);
        mapping.erase(t);
        --size;
        Heapify(0);
    }

    void insert(T);
    void remove(T); 
    
    void print(){
        for(int i = 0; i < size; ++i){
            cout<<v[i]<<endl;
        }
    }
    
    void printmap(){
        for(int i = 0; i < size; ++i){
            int idx = mapping[v[i]];
            cout<<"idx "<<idx<<endl;
        }
    }
};

template <typename T>
HashHeap<T> :: HashHeap(vector<T> input){
    for(int i = 0; i < input.size(); ++i){
        v.push_back(input[i]);
        mapping[input[i]] = size;
        ++size;
    }
    BuildHeap();
}

template <typename T>
void HashHeap<T> :: BuildHeap(){
    for(int i = size/2 - 1; i >= 0; --i){
            Heapify(i);
    }
}

template <typename T>
void HashHeap<T> :: Heapify(int cur_idx){
    int large = cur_idx;
    int l = cur_idx*2+1;
    int r = cur_idx*2+2;

    if(l < size && v[l] > v[large]){
        large = l;
    }
    if(r < size && v[r] > v[large]){
        large = r;
    }
    if(large != cur_idx){
        Swap(v[large], v[cur_idx]);
        Heapify(large);
    }
}

template <typename T>
void HashHeap<T> :: Swap(T &n1, T &n2){
    //record previous index
    int idx1 = mapping[n1];
    int idx2 = mapping[n2];
    //swap item in container
    T t = n1;
    n1 = n2;
    n2 = t;
    //update index
    mapping[n1] = idx2;
    mapping[n2] = idx1;
}

template <typename T>
void HashHeap<T> :: insert(T t){
    if(size < v.size()){
        v[size] = t;
    }
    else{
        v.push_back(t);
    }
    mapping[t] = size;
    ++size;
    //swap with top item
    Swap(v[size-1],v[0]);
    Heapify(0);
}

template <typename T>
void HashHeap<T> :: remove(T t){
    //get index of t in the container
    int idx = mapping[t];
    //swap item to delete with last item
    Swap(v[idx], v[size-1]);
    mapping.erase(t);
    --size;
    Heapify(0);
}

int main(){
    int arr[] = {4,2,5,1,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    
    HashHeap<int> myheap(v);
    myheap.print();
    cout<<endl;
    return 0;
}