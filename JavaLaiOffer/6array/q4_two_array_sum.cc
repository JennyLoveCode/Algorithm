/*
From 2 arrays, pick one element from each of them, sum = k.
A = {1, 3, 5, 6, 10}
B = {2, 4, 7, 8, 12}
k = 10
*/
#include <iostream>
using namespace std;

void Sum(int[], int, int[], int, int);

int main(){
    int A[] = {1, 3, 5, 6, 10};
    int B[] = {2, 4, 7, 8, 12};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    int k = 10;
    Sum(A,m,B,n,k);
    return 0;
}

void Sum(int A[], int m, int B[], int n, int k){
    int i = 0;
    int j = n-1;
    
    while(i < m && j >= 0){
        if(A[i] + B[j] == k){
            cout<<A[i]<<" "<<B[j]<<endl;
            ++i;
            --j;
        }
        else if(A[i] + B[j] < k){
            ++i;
        }
        else{
            --j;
        }
    }
}