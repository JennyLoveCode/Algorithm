/*
1 Merge two sorted arrays A and B, we assume A has enough space, merge to A array.
*/
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &, const vector<int> );
void Print(vector<int> );

int main(){
    int arr1[] = {1,3,5,8,10};
    int arr2[] = {2,4,6,7,9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> a(arr1, arr1+n);
    vector<int> b(arr2, arr2+m);
    Merge(a, b);
    Print(a);
    return 0;
}

void Merge(vector<int> &a, const vector<int> b){
    int n = a.size();
    int m = b.size();
    //resize vector a
    for(int i = 0; i < m; i++){
        a.push_back(0);
    }
    //merge from back to front
    int i = n-1, j = m-1, k = m+n-1;
    while(i >=0 && j >=0){
        if(a[i] > b[j]){
            a[k--] = a[i--];
        }
        else{
            a[k--] = b[j--];
        }
    }
    while(i >= 0){
        a[k--] = a[i--];
    }
    while(j >= 0){
        a[k--] = b[j--];
    }
}

void Print(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}