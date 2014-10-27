/*
Given n non-negative integers a1, a2 ... an, where each represents a point at coordinate(i, ai). n vertical
lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis froms a container, such that the container contains the most
water.
*/
#include <iostream>
using namespace std;

int MostWater(int arr[], int n);

int main(){
    int arr[] = {5,3,6,3,2,1,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int res = MostWater(arr, n);
    cout<<res<<endl;
    return 0;
}

int MostWater(int arr[], int n){
    int start = 0;
    int end = n-1;
    int result = 0;
    int cur = 0;
    
    while (start < end) {
        int width = end-start;
        if (arr[start] < arr[end]) {
            cur = arr[start] * width;
            ++start;
        } else {
            cur = arr[end] * width;
            --end;
        }
        result = max(cur, result);
    }
    return result;
}