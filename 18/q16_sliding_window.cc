/*
Q16: (Array) Sliding window of size k, always return the max element in 
the window size.
1 3 2 5 8 9 4 7 3, WINDOW size k == 3

1 3 2
____
3
____
5
____
8
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> k_max_sliding_window(const vector<int> &, int);
void print(const vector<int> &);

int main(){
    int arr[] = {1,3,2,5,8,9,4,7,3};
    int k = 3;
    const vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> result = k_max_sliding_window(v,k);
    print(v);
    print(result);
}

vector<int> k_max_sliding_window(const vector<int> &v, int k){
    vector<int> result;
    deque<int> index;
    //initialization
    int i = 0;
    for(; i < k; i++){
        if(!index.empty() && v[i] > v[index.back()]){
            index.pop_back();
        }
        index.push_back(i);
    }
    result.push_back(v[index.front()]);
    for(; i < v.size(); i++){
        while(!index.empty() && v[i] >= v[index.back()]){
            index.pop_back();
        }
        while(!index.empty() && i-index.front() >= k){
            index.pop_front();
        }
        index.push_back(i);
        result.push_back(v[index.front()]);
    }
    return result;
}

void print(const vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}









