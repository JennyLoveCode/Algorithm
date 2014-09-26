/*
Q1:   Given an array of integers, how to divide the whole array into two parts, with their sums 
equal to each other.
*/
#include <iostream>
#include <vector>
using namespace std;

void DFS(const vector<int> &, vector<int> , int , int , int );
void Print(vector<int> );

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    const vector<int> v(arr, arr+n);
    vector<int> sol;
    int sum = 0;
    for(int i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    DFS(v,sol,sum,0,0);
    return 0;
}

void DFS(const vector<int> &v, vector<int> sol, int sum, int idx, int cur){
    //base case
    if(idx > v.size()){
        return;
    }
    if(cur == 0.5*sum &&idx == v.size()){
        Print(sol);
        return;
    }
    //recursive
    DFS(v,sol,sum,idx+1,cur);
    sol.push_back(v[idx]);
    DFS(v, sol, sum, idx+1, cur+v[idx]);
}

void Print(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}