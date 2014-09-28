/*
Q20.(array) Given a sorted array, 找一个target number == x, find how many x exists 
in this array.
1 2 3 4 5 6 6 6 6 6 6 6 6 6 6 7 8 9 10
left m right
*/
#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> &, int);
int upper_bound(vector<int> &, int);

int main(){
    int arr[] = {1,2,3,4,5,6,6,6,6,6,6,7,8,9,10};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int target = 6;
    int lowerbound = lower_bound(v, target);
    int upperbound = upper_bound(v, target);
    
    int result = upperbound - lowerbound;
    cout<<result<<endl;
    return 0;
}

//find lower_bound of target: left indicates the first occurrence of the target
//use left and right to limit the range
int lower_bound(vector<int> &v, int target){
    int left = 0;
    int right = v.size()-1;
    while(left < right){
        int mid = left + (right - left)/2;
        if(v[mid] < target){
            left =  mid+1;
        }
        else if(v[mid] == target){
            right = mid;
        }
        else{
            right = mid;
        }
    }
    return left;
}

//find upper_bound of target : first one large than target
int upper_bound(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    while(left < right){
        int mid = left + (right-left)/2;
        if(v[mid] < target){
            left = mid+1;
        }
        else if(v[mid] == target){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}