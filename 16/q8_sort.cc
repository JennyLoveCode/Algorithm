/*
Q8: (Array) Given an unsorted array A[N] with positive, negative numbers and zeros. 
How to move all negative numbers to the left side of the array, move zeros in the 
middle of the array, and move positive numbers to the right side of the array?
Requirements: O(n) time complexity.
*/
#include <algorithm>
#include <iostream>
using namespace std;

void sort(int arr[], int n){
    int i = 0;
    int k = 0;
    int j = n-1;
    while(k <= j){
        if(arr[k] > 0){
            swap(arr[k],arr[j--]);
        }
        else if(arr[k] < 0){
            swap(arr[k++], arr[i++]);
        }
        else{
            k++;
        }
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {3,1,-3,2,5,6,-5,0,5,3,-9,5,88};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);
    sort(arr, n);
    print(arr, n);
    return 0;
}