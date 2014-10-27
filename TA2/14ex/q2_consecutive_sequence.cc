/*
Longest consecutive sequence.
		array, integer, [1, 2, 19, 4, 3, 5]
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int LCS (int arr[], int n);

int main () {
    int arr[] = {1,2,19,4,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = LCS(arr, n);
    cout<<res<<endl;
    return 0;
}

int LCS (int arr[], int n) {
    unordered_set<int> s;
    //build set
    for (int i = 0; i < n; ++i) {
        s.insert(arr[i]);
    }
    int res = INT_MIN;
    //traverse array
    for (int i = 0; i < n; ++i) {
        if (s.find(arr[i]) == s.end()) {
            continue;
        }
        int len = 1;
        int val = arr[i];
        while (s.find(val -1) != s.end()) {
            ++len;
            s.erase(val-1);
            --val;
        }
        val = arr[i];
        while (s.find(val+1) != s.end()) {
            ++len;
            s.erase(val+1);
            ++val;
        }
        res = max(res, len);
    }
    return res;
}