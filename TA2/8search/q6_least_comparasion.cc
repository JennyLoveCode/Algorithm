/*
Find the smallest and largest in an array in least number of comparison times.
2  5  8  1   4  7  6  0     -> 5	8   7	6	    2  1   4  0 
O(n/2 + n/2 + n/2)
*/
#include <iostream>
#include <vector>
using namespace std;

void Compare(vector<int> );

int main(){
    int arr[] = {2,5,8,1,4,7,6,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    Compare(v);
    return 0;
}

void Compare(vector<int> v){
    int small = INT_MAX;
    int large = INT_MIN;
    for(int i = 0; i+1 < v.size(); i += 2){
        if(v[i] < v[i+1]){
            small = min(small, v[i]);
            large = max(large, v[i+1]);
        }
        else{
            small = min(small, v[i+1]);
            large = max(large, v[i]);
        }
    }
    //in case the size value is odd
    small = min(small, v[v.size()-1]);
    large = max(large, v[v.size()-1]);
    cout<<"smallest "<<small<<endl;
    cout<<"largest "<<large<<endl;
}