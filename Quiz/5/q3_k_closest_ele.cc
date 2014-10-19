/*
Q3 Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].  
Assuming X must be in the array.

Examples: Input: K = 4, X = 36.     
arr[] = {12, 16, 22, 30, 36, 39, 42, 45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> FindKClosest(int arr[], int n, int x, int k);
int BinarySearch(int arr[], int left, int right, int x);
void print (vector<int> &v);

int main(){
    int arr[] = {12, 16, 22, 30, 36, 39, 42, 45, 48, 50, 53, 55, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int x = 36;
    
    vector<int> res = FindKClosest(arr, n, x, k);
    print(res);
    return 0;
}

vector<int> FindKClosest(int arr[], int n, int x, int k){
    if (k >= n) {
        return vector<int>(arr, arr+n);
    }
	vector<int> res;
	int pos = BinarySearch(arr, 0, n-1, x);
	int left = pos-1;
	int right = pos+1;
	int count = 0;
	if (arr[pos] != x) {
	    res.push_back(arr[pos]);
	    ++count;
	    if (count == k) {
	        return res;
	    }
	} 
    for (; left >= 0 || right < n; count++ ) {
	    if (count == k) return res;
	    if( left >= 0 && abs(arr[left] - arr[pos]) < abs(arr[right] - arr[pos])){
		    res.push_back(arr[left]);
		    --left;
        } else if (right < n  && abs(arr[left] - arr[pos]) >= abs(arr[right] - arr[pos]) ) {
	        res.push_back(arr[right]);
	        ++right;
        }
    }
    return res;
}

int BinarySearch(int arr[], int left, int right, int x){
	while (left < right - 1) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;
        } else if (arr[mid] < x) {
	        left = mid;
        } else {
	        right = mid;
        }
    }
    if(abs(arr[left]-x) < abs(arr[right]-x)){
        return left;
    } else {
        return right;
    }
}

void print (vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}