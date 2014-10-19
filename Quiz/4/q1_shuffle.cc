/*
Given a sequence of integers [1, 1, 2, 2, 3, 3, ...., n - 1, n - 1, n, n] 
please shuffle the input integer array, such that the output integer array 
satisfy this condition: between each two i's, they are exactly i integers 
(for example: between the two 1s, there is one number, between the two 2's 
there are two numbers) 
example n = 3, 
input 1, 1, 2, 2, 3, 3 
output 2, 3, 1, 2, 1, 3 
*/
#include <iostream>
#include <vector>
using namespace std;

void Shuffle(vector<int> &num, int cur);
bool IsValid(vector<int> &num, int cur, int idx);
void Swap(vector<int> &num, int cur, int idx);
void Print(vector<int> &v);

int main(){
    int arr[] = {1,1,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> num(arr, arr+n);
    Shuffle(num, 0);
    return 0;
}

void Shuffle(vector<int> &num, int cur){
    //base case
    if(cur == num.size()){
        Print(num);
        return;
    }
    //recursive
    for(int i = cur; i < num.size(); ++i){
        if(IsValid(num, cur, i)){
            Swap(num, cur, i);
            Shuffle(num, cur+1);
            Swap(num, cur, i);
        }
    }
}

bool IsValid(vector<int> &num, int cur, int idx){
    int value = num[idx];
    int begin = cur-value-1;
    if(begin < 0){
        return true;
    }
    if(num[begin] != value){
        return false;
    }
    for(int i = begin+1; i < cur; ++i){
        if(num[i] == value){
            return false;
        }
    }
    return true;
}

void Swap(vector<int> &num, int cur, int idx){
    int t = num[cur];
    num[cur] = num[idx];
    num[idx] = t;
    return;
}

void Print(vector<int> &num){
    for(int i = 0; i < num.size(); ++i){
        cout<<num[i]<<" "; 
    }
    cout<<endl;
}