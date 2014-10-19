/*
Print out all possible subset that sum to half of the sum of the array. 
If no such subset, print null.
*/
#include <iostream>
#include <vector>
using namespace std;

void SubsetSum(vector<int> &v);
void SubsetSumHelp(vector<int> &v, int target, vector<int> &solu, int start);
int Sum(vector<int> &v);
void Print(vector<int> &v);

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    
    SubsetSum(v);
    return 0;
}

void SubsetSum(vector<int> &v){
    int sum = Sum(v);
    vector<int> solu;
    SubsetSumHelp(v, sum/2, solu, 0);
}

void SubsetSumHelp(vector<int> &v, int target, vector<int> &solu, int start){
    //base case;
    if(Sum(solu) == target){
        Print(solu);
        return;
    }
    for(int i = start; i < v.size(); ++i){
        solu.push_back(v[i]);
        //if all numbers are positive, discart next steps if current sum > target
        if(Sum(solu) > target){
            solu.pop_back();
            continue;
        }
        SubsetSumHelp(v, target, solu, i+1);
        solu.pop_back();
    }
}

int Sum(vector<int> &v){
    int sum = 0;
    for(int i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    return sum;
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}