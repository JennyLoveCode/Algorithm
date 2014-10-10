/*
quick sort
*/
#include <iostream>
#include <algorithm>
using namespace std;

void QuickSort(int[], int , int );
int Partition(int[], int , int );
void Print(int[], int);

int main(){
    int arr[] = {5,2,1,6,4,3,5,3,1,1,1,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr, 0, n-1);
    Print(arr, n);
    return 0;
}

void QuickSort(int arr[], int l, int r){
    if(l < r){
        int p = Partition(arr, l, r);
        QuickSort(arr, l, p-1);
        QuickSort(arr, p+1, r);
    }
}

int Partition(int arr[], int l, int r){
    int x = arr[r];
    int idx = l-1;
    for(int i = l; i < r; ++i){
        if(arr[i] < x){
            swap(arr[++idx], arr[i]);
        }
    }
    swap(arr[++idx],arr[r]);
    return idx;
}

void Print(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}