/*
array of integers, find the longest subarray, the average of the subarray is < k.
a’[i] = a[i] - k; → sum of the subarray < 0.
b’[i] = a’[0] + a’[1] + … + a’[i]
*/
#include <iostream>
#include <vector>
using namespace std;

int main () {

}

vector<int> FindLongestSub (int arr[], int n, int k) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(arr[i]-k);
    }
    //get sum of continuous subarray
    for (int i = 1; i < n; ++i) {
        v[i] = v[i-1]+v[i];
    }
    return 
}