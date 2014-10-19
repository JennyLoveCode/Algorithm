/*
Given an array contains elements from 1 to n, there are two elements repeated. 
We want to find out those two elements.

for example: {3,2,1,2,3}
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> Repeated(int arr[], int n);

int main(){
    int arr[] = {3,2,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> res = Repeated(arr, n);
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}

vector<int> Repeated(int arr[], int n){
    int count = 0;
    vector<int> result;

    for(int i = 0; i < n; ++i){
        //early termination
        if(count == 2){
            break;
        }
        int idx = abs(arr[i]);
        //find element repeated
        if(arr[idx] < 0){
            result.push_back(idx);
            count++;
        }
        //make element negative in corresponding index
        arr[idx] = -arr[idx];
    }
    
    return result;
}