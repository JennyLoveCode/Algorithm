/*
merge sort
*/
#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int> &, int ,int );
void Merge(vector<int> &, int , int );
void Print(vector<int> );

int main(){
    int arr[] = {4,1,5,3,2,7,8,6,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    MergeSort(v, 0, n-1);
    Print(v);
    return 0;
}

void MergeSort(vector<int> &v, int l,int r){
    if(l < r){
        int m = l+(r-l)/2;
        MergeSort(v, l, m);
        MergeSort(v, m+1, r);
        Merge(v,l, r);
    }
}

void Merge(vector<int> &v, int l, int r){
    int m = l+(r-l)/2;
    vector<int> a;
    for(int i = l; i < m+1; ++i){
        a.push_back(v[i]);
    }
    vector<int> b;
    for(int i = m+1; i < r+1; ++i){
        b.push_back(v[i]);
    }
    
    int i = 0, j =0, k = l;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            v[k++] = a[i++];
        }
        else{
            v[k++] = b[j++];
        }
    }
    
    while(i < a.size()){
        v[k++] = a[i++];
    }
    
    while(j < b.size()){
        v[k++] = b[j++];
    }
}

void Print(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}