/*
Q39 给一个integer array，允许duplicates，而且其中某个未知的integer的 duplicates的个数占了
整个array的一大半。如何有效的找出这个integer (Using constant space O(1)) ?
*/
#include <iostream>
using namespace std;

int FindDuplicate(int[], int );

int main(){
    int arr[] = {1,3,5,5,5,3,3,6,7,8,5,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = FindDuplicate(arr, n);
    cout<<result<<endl;
    return 0;
}

int FindDuplicate(int arr[], int n){
    int candidate;
    int count = 0;
    //traverse array
    for(int i = 0; i < n; ++i){
        if(count == 0){
            candidate = arr[i];
        }
        if(arr[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    //check
    count = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == candidate){
            count++;
        }
    }
    if(count > n/2){
        return candidate;
    }
    else{
        return INT_MIN;
    }
}