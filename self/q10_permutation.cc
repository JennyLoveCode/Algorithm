/*
Given a collection of numbers, return all possible permutations
*/
#include <iostream>
#include <vector>
using namespace std;

void Permu (vector<int> v);
void PermuHelp (vector<int> &v, int idx);
void PermuDup (vector<int> v);
void PermuDupHelp (vector<int> &v, int idx);
void swap (int &a, int &b);
void print (vector<int> &v);

int main () {
    int arr[] = {1,2,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    PermuDup(v);
    return 0;
}

void Permu (vector<int> v) {
    PermuHelp(v, 0);
}

void PermuHelp (vector<int> &v, int idx) {
    if (idx == v.size()) {
        print(v);
        return;
    }
    for (int i = idx; i < v.size(); ++i) {
        swap(v[idx], v[i]);
        PermuHelp(v, idx+1);
        swap(v[idx], v[i]);
    }
}

void PermuDup (vector<int> v) {
    PermuDupHelp(v, 0);
}

void PermuDupHelp (vector<int> &v, int idx) {
    if (idx == v.size()) {
        print(v);
        return;
    }
    for (int i = idx; i < v.size(); ++i) {
        if (i != idx && v[i] == v[i-1]) {
            continue;
        }
        swap(v[idx], v[i]);
        PermuDupHelp(v, idx+1);
        swap(v[idx], v[i]);
    }
}

void swap (int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void print (vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}