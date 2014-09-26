/*
Search in a sorted  array for first occurrence index of k.
*/
#include <iostream>
#include <vector>
using namespace std;

int LeftBoardIT(vector<int> , int );
int LeftBoard(vector<int> , int , int , int );

int main(){
    int arr[] = {1,1,1,1,1,4,5,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int r1 = LeftBoardIT(v, 1);
    int r2 = LeftBoard(v,0, n-1, 1);
    cout<<r1<<" "<<r2<<endl;
    return 0;
}

int LeftBoardIT(vector<int> v, int target){
    int left = 0;
    int right = v.size();
    while(left < right - 1){ //avoid dead loop: if left neighbors right, terminate
        int mid = left+(right-left)/2;
        if(v[mid] == target){
            right = mid;
        }
        else if(v[mid] < target){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    if(v[left] == target){
        return left;
    }
    if(v[right] == target){
        return right;
    }
    return -1;
}

int LeftBoard(vector<int> v, int left, int right, int target){
    //base case
    if(left > right) return -1;
    if(left == right && v[left] == target) return left;
    if(left+1 == right){
        if(v[left] == target)
            return left;
        if(v[right] == target)
            return right;
    }
    //recursive rule
    int mid = left+(right-left)/2;
    if(v[mid] == target) 
        return LeftBoard(v, left, mid, target);
    else if(v[mid] < target)
        return LeftBoard(v, mid, right, target);
    else 
        return LeftBoard(v, left, mid, target);
}