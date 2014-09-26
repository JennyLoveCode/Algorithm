/*
2.In a sorted array for the largest element that is less than k.
k exist or k not exist
*/
#include <iostream>
#include <vector>
using namespace std;

int LessThan(vector<int> , int );

int main(){
    int arr[] = {1,3,5,8,9,11,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int k = 2;
    int result = LessThan(v,k);
    cout<<result<<endl;
    return 0;
}

int LessThan(vector<int> v, int k){
    int left = 0;
    int right = v.size()-1;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(v[mid] >= k){
            right = mid-1;
        }
        else if(v[mid] < k){
            left = mid;
        }
    }
    cout<<"left"<<v[left]<<endl;
    cout<<"right"<<v[right]<<endl;
    int l = left-1 >= 0 ? left-1:left;
    int r = right+1 <= v.size()? right+1: right;
    int diff = INT_MAX;
    int res = INT_MAX;
    for(int i = l; i <= r; i++){
        if(k-v[i] > 0 && k-v[i]<diff){
            diff = k-v[i];
            res = v[i];
        }
    }
    return res;
}