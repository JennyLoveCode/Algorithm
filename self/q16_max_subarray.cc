/*
Find the contiguous subarray within an array(containing at least on number) which has 
the largest sum
e.g {-2, 1,-3, 4,-1, 2, 1, -5, 4}
result is {4, -1,2,1} return 6
*/
#include <iostream>
#include <vector>
using namespace std;

int MaxSubarray (int arr[], int n);

int main () {
    int arr[] = {-2, 1,-3, 4,-1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = MaxSubarray(arr, n);
    cout<<res<<endl;
    return 0;
}

int MaxSubarray (int arr[], int n) {
    int res = INT_MIN;
    vector<int> state(n, 0);
    state[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        state[i] = max(state[i-1]+arr[i], arr[i]);
        res = max(res, state[i]);
    }
    return res;
}