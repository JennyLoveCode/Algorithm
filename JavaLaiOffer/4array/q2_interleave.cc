/*
Interleaving Positive and Negative Numbers
Given an int array, how do you interleave the positive and negative numbers?
(Guaranteed that  # of positive >= # of negative numbers).
Example, {1, 2, 4, -2, -3, 3, -1} → {1, -2, 2, -3, 3, -1, 4}
*/
#include <iostream>
#include <algorithm>
using namespace std;

void Interleave(int[], int );
void Reorder(int[], int , int );
void Rotate(int[], int , int , int , int );
void Reverse(int[], int , int );
void Print(int[], int );

int main(){
    int arr[] = {1,-2,3,4,5,-6,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Interleave(arr, n);
    return 0;
}

void Interleave(int arr[], int n){
    //partition, first part is positive, and then negative
    int p = -1;
    int q = n-1;
    int cur = 0;
    while(cur < q){
        if(arr[cur] > 0){
            arr[++p] = arr[cur++]; 
        }
        else{
            swap(arr[cur], arr[q--]);
        }
    }
    Print(arr, n);
    //divide and conquer to reorder array
    int positive_num = q+1;
    int m;
    //update new length to reorder
    if(positive_num > n/2){
        m = (n-positive_num)*2;
        int diff = n - m;
        for(int i = positive_num -1, j = n-1; diff > 0; diff--){
            swap(arr[i--], arr[j--]);
        }
    }
    else{
        m = positive_num*2;
    }
    Print(arr, n);
    Reorder(arr, 0, m-1);
    cout<<"==============="<<endl;
    Print(arr, n);
}

//divide and conquer
void Reorder(int arr[], int begin, int end){
    cout<<" REORDER "<<endl;
    Print(arr, end-begin+1);
    if(begin <= end-3){
        //rotate the central part of array
        int num = end-begin+1;
        int begin1 = begin + num/4;
        int end1 = begin + num/2-1;
        int begin2 = begin + num/2;
        int end2 = begin+3*num/4-1;
        Rotate(arr, begin1, end1, begin2, end2);
        Reorder(arr, begin,begin+2*(num/4)-1 );
        Reorder(arr, begin+2*(num/4), end);
    }
}

void Rotate(int arr[], int begin1, int end1, int begin2, int end2){
    Reverse(arr, begin1, end1);
    Reverse(arr, begin2, end2);
    Reverse(arr, begin1, end2);
}

void Reverse(int arr[], int begin, int end){
    int i = begin;
    int j = end;
    while(i < j){
        swap(arr[i++],arr[j--]);
    }
}

void Print(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}