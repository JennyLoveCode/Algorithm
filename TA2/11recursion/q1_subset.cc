/*
Print all subsets for an array
*/
#include <iostream>
#include <vector>
using namespace std;

void Subset(int arr[], int n);
void SubsetHelp(int arr[], int n, vector<int> &solu, int cur);
void SubsetWithDup(int arr[], int n);
void SubsetWithDupHelp(int arr[], int n, vector<int> &solu, int start);
void Print(vector<int> &v);

int main(){
    int arr[] = {1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //Subset(arr, n);
    SubsetWithDup(arr, n);
    return 0;
}

void Subset(int arr[], int n){
    vector<int> solu;
    SubsetHelp(arr, n, solu, 0);
}

void SubsetHelp(int arr[], int n, vector<int> &solu, int cur){
    //base case
    if(cur == n){
        Print(solu);
        return;
    }
    //recursive rule
    SubsetHelp(arr, n, solu, cur+1);
    solu.push_back(arr[cur]);
    SubsetHelp(arr, n, solu, cur+1);
    solu.pop_back();
}

void SubsetWithDup(int arr[], int n){
    vector<int> solu;
    SubsetWithDupHelp(arr, n, solu, 0);
}

void SubsetWithDupHelp(int arr[], int n, vector<int> &solu, int start){
    Print(solu);

    for(int i = start; i < n; ++i){
        //skip duplicates in array
        if(i != start && arr[i] == arr[i-1]){
            continue;
        }
        solu.push_back(arr[i]);
        SubsetWithDupHelp(arr, n, solu, i+1);
        solu.pop_back();
    }
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}