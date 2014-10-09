/*
Google电面
Difference between two sorted arrays, (what if not sorted)?
A = [1, 2, 2, 7, 9]
B = [2, 2, 5, 6, 7]

A not B = [1, 9]
B not A = [5, 6]
*/
#include <iostream>
#include <vector>
using namespace std;

void DiffArr(int[], int, int[], int , vector<int> &, vector<int> &);
void Print(vector<int> &);

int main(){
    int A[] = {1,2,2,7,9};
    int B[] = {2,2,5,6,7};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    vector<int> not_a;
    vector<int> not_b;
    DiffArr(A,m,B,n,not_a,not_b);
    Print(not_a);
    Print(not_b);
    return 0;
}

void DiffArr(int A[], int m, int B[], int n, vector<int> &not_b, vector<int> &not_a){
    int i = 0;
    int j = 0;
    
    while(i < m && j < n){
        //A not B
        if(A[i] < B[j]){
            not_b.push_back(A[i]);
            ++i;
        }
        //A and B
        else if(A[i] == B[j]){
            ++i;
            ++j;
        }
        //B not A
        else{
            not_a.push_back(B[j]);
            ++j;
        }
    }
    
    //A not B
    while(i < m){
        not_b.push_back(A[i]);
        ++i;
    }
    
    //B not A
    while(j < n){
        not_a.push_back(B[j]);
    }
    
    return;
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}