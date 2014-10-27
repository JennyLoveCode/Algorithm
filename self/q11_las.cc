/*
The longest Increasing Subsequence (LIS) problem is to find the length of the longest 
subsequence of a given sequence such that all elements of the subsequence are sorted in 
increasing order. For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } 
is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/
#include <iostream>
#include <vector>
using namespace std;

int LIS (int arr[], int n);

int main () {
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 } ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = LIS(arr, n);
    cout<<res<<endl;
    return 0;
}

int LIS (int arr[], int n) {
    vector<int> state(n, 1);
    
    for (int i = 1; i < n; ++i) {
        int len = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                len = max(len, state[j]+1);
            }
        }
        state[i] = len;
    }
    return state[n-1];
}