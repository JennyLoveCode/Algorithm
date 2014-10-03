/*
2-sum, how many pairs sum to target, with/without duplicates? 

Given an int array, find if(all) there are 4 elements in the array such that A + B + C = D.

Given an int array, find the number of pairs(i, j) that Math.abs(a[i] - a[j]) = target.

Example, {1, 3, 1, 3}, target = 2, # of pairs is 4: (0, 1), (0, 3), (1, 2), (2, 3)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int FindAll(int[], int , int );

int main(){
    int arr[] = {1,1,3,3,7,7,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    int result = FindAll(arr, n, target);
    cout<<result<<endl;
    return 0;
}
//abs(arr[i] - arr[j]) = target
int FindAll(int arr[], int n, int target){
    unordered_map<int, int> mapping;
    //build mapping
    for(int i = 0; i < n; ++i){
        mapping[arr[i]]++;
    }
    int count = 0;
    //traverse mapping
    unordered_map<int, int> :: iterator iter;
    for(iter = mapping.begin(); iter != mapping.end(); ++iter){
        int another = iter->first+target;
        if(mapping.find(another) != mapping.end()){
            count += iter->second*mapping[another];
        }
    }
    return count;
}

//Given an int array, find if(all) there are 4 elements in the array such that A + B = C + D.
