/*
Sorted array A, int k,Output: All pairs of indices (i, j) such that
1). A[j] - A[i] = k
2). A[j] + A[i] = k
*/
#include <iostream>
using namespace std;

void Pairs(int[], int, int);

int main(){
    int arr[] = {1,2,5,8,9,11,12,15,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    Pairs(arr,n,k);
    return 0;
}

void Pairs(int arr[], int n, int k){
    int i = 0;
    int j = 1;

    while(j < n){
        if(arr[j] - arr[i] == k){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            ++i;
        }
        else if(arr[j] - arr[i] > k){
            ++i;
        }
        else{
            ++j;
        }
        //move j forward if i==j
        if(i == j){
            ++j;
        }
    }
    
    while(i < n && arr[j] - arr[i] >= k){
        ++i;
    }

    return;
}