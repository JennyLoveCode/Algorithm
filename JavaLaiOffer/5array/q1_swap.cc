/*
1. for an int array, swap the elements to make it as: the element on 
odd index  >= the two neighbors on even index.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void SwapArr(vector<int> &);
void Print(const vector<int> &);

int main(){
    int arr[] = {2,1,5,3,6,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    SwapArr(v);
    Print(v);
    return 0;
}

void SwapArr(vector<int> &v){
    sort(v.begin(), v.end());
    for(int i = 2; i < v.size(); i += 2){
        swap(v[i-1], v[i]);
    }
}

void Print(const vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}