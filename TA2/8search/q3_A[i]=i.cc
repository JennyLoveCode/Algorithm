/*
3. Find an element in a sorted array that A[i] == i.
distinct integer
0  1 2 3 4 5 6 7 8
-1 0 1 2 3 5 8 9 10
*/
#include <iostream>
#include <vector>
using namespace std;

void Find(vector<int> );

int main(){
    int arr[] = {-1,0,1,2,3,5,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    Find(v);
    return 0;
}

void Find(vector<int> v){
    int left = 0;
    int right = v.size()-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(v[mid] == mid){
            cout<<v[mid]<<endl;
            return;
        }
        else if(v[mid] > mid){
            right = mid -1;
        }
        else{
            left = mid+1;
        }
    }
}