/*
Given an unsorted array, find the subarray that has the greatest sum. Return the sum.
*/
#include <iostream>
#include <vector>
using namespace std;

int LargestSubarray(vector<int>);

int main(){
    int arr[] = {1,2,3,-8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int result = LargestSubarray(v);
    cout<<result<<endl;
    return 0;
}

int LargestSubarray(vector<int> v){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i = 0; i < v.size(); i++){
        max_ending_here += v[i];
        if(max_ending_here + v[i] < 0){
            max_ending_here = 0;
        }
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}
/*
Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
*/