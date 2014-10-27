/*
Q3  Given a sorted array (sorted in non-decreasing order) of positive numbers, find the smallest positive 
integer value that cannot be represented as sum of elements of any sub-sequence of the given array. 
*/

#include <iostream>
#include <vector>
using namespace std;

int Smallest(int arr[], int n);

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int res = Smallest(arr, n);
    cout<<res<<endl;
    return 0;
}

int Smallest(int arr[], int n){
    vector<int> mat;
    mat.push_back(arr[0]);;
    
    for(int i = 1; i < n; ++i){
        if(mat[i-1] < arr[i]-1){
            return mat[i-1]+1;
        }
        mat.push_back(mat[i-1]+arr[i]);
    }
    return mat[n-1]+1;
}