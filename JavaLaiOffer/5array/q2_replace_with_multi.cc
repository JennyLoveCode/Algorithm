/*
For an int array, replace each element with the multiplication of all elements 
other than that element.
{1, 2, 3, 4} → {24, 12, 8, 6}
*/
#include <iostream>
#include <vector>
using namespace std;

void Multi(vector<int> &v);
void Print(vector<int> &v);

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    Multi(v);
    Print(v);
    return 0;
}

void Multi(vector<int> &v){
    int n = v.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    //get left array and right array
    for(int i = 1; i < n; ++i){
        left[i] = left[i-1]*v[i-1];
        right[n-i-1] = right[n-i]*v[n-i];
    }
    //replace each element 
    for(int i = 0; i < n; ++i){
        v[i] = left[i]*right[i];
    }
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}