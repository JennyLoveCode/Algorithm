/*
Leetcode 2.1.14
Example: [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <iostream>
#include <vector>
using namespace std;

int TrapWater(int arr[], int n);

int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = TrapWater(arr, n);
    cout<<result<<endl;
    return 0;
}

int TrapWater(int arr[], int n){
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    
    //get maximum left and right height for each element in array
    for(int i = 1; i < n; ++i){
        left[i] = max(arr[i-1], left[i-1]);
        right[n-i-1] = max(arr[n-i], right[n-i]);
    }
    int sum = 0;
    //calculate trapping water for each element in array
    for(int i = 0; i < n; ++i){
        int h = min(left[i], right[i]);
        if(h > arr[i]){
            sum += h-arr[i];
        }
    }
    return sum;
}