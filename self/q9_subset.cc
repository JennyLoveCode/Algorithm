/*
Given a set of distinct integers, return all possible subsets.
*/
#include <iostream>
#include <vector>
using namespace std;

void Subset (vector<int> v);
void SubsetHelp (vector<int> &v, int idx, vector<int> &solu);
void SubsetDup (vector<int> &v);
void SubsetDupHelp(vector<int> &v, int start, vector<int> &solu);
void print (vector<int> &v);

int main () {
    int arr[] = {1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    //Subset(v);
    SubsetDup(v);
    return 0;
}

void Subset (vector<int> v) {
    vector<int> solu;
    SubsetHelp(v, 0, solu);
}

void SubsetHelp (vector<int> &v, int idx, vector<int> &solu) {
    //base case
    if (idx == v.size()) {
        print(solu);
        return;
    }
    //not select
    SubsetHelp(v, idx+1, solu);
    solu.push_back(v[idx]);
    SubsetHelp(v, idx+1, solu);
    solu.pop_back();
}

void SubsetDup (vector<int> &v) {
    vector<int> solu;
    SubsetDupHelp(v, 0, solu);
}

void SubsetDupHelp(vector<int> &v, int start, vector<int> &solu){
    print(solu);
    for (int i = start; i < v.size(); ++i) {
        if (i != start && v[i] == v[i-1]) {
            continue;
        }
        solu.push_back(v[i]);
        SubsetDupHelp(v, i+1, solu);
        solu.pop_back();
    }
}

void print (vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}