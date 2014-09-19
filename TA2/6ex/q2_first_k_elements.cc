/*
2. Find the first k smallest elements in an array for length n.
*/

/*
(1) sort, find the former k elements, 
quicksort: O(n^2), O(1)
mergesort: O(nlogn), O(n)
(2) heapify: O(n) + klogn
(3) priority queue: push k elements into priority maximum queue, 
push the rest of elements into queue and pop them. 
O(k) + (n -k) * logk, O(k)
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

vector<int> FirstKElements(vector<int> &, int );

int main(){
    int arr[] = {9,1,3,5,6,2,8,4,7,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int k = 6;
    vector<int> result = FirstKElements(v, k);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

vector<int> FirstKElements(vector<int> &v, int k){
    priority_queue<int, vector<int>, less<int> > q;
    vector<int> result;
    //push k elements into the max heap
    for(int i = 0; i < k; i++){
        q.push(v[i]);
    }
    for(int i = k; i < v.size(); i++){
        if(v[i] < q.top()){
            q.pop();
            q.push(v[i]);
        }
    }
    while(!q.empty()){
        result.push_back(q.top());
        q.pop();
    }
    return result;
}