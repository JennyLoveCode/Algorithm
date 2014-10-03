/*
2 int[] array, rotated sorted array, rotation position. (no duplicate elements).
*/
#include <iostream>
using namespace std;

int RotatePos(int[], int );

int main(){
    int arr[] = {10,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = RotatePos(arr,n);
    cout<<result<<endl;
    return 0;
}

int RotatePos(int arr[], int n){
    int left = 0;
    int right = n-1;
    //corner case: only two elements in array
    if(n==2 && arr[0]>arr[1]){
        return 1;
    }
    while(left < right){
        int mid = left+(right-left)/2;
        //rotate position
        if(arr[mid-1] > arr[mid] && (mid+1 >=n || arr[mid] < arr[mid+1])){
            return mid;
        }
        //discard left part
        else if(arr[left] < arr[mid]){
            left = mid+1;
        }
        //discard right part
        else{
            right = mid-1;
        }
    }
    return -1;
}