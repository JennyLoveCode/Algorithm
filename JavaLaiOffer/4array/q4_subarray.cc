/*
4 Find the subarray, the sum is closest to 0.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

void FindSubarray0(int [], int );
void FindSubCloestK(int [], int , int );
bool Compare(const pair<int, int> &, const pair<int, int> &);
void Print(int [], int , int );

int main(){
    int arr[] = {5,6,-1,1,2,8,6,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Here are subarray whose sum is 0 "<<endl;
    FindSubarray0(arr, n);
    
    int k = 15;
    cout<<"closest to "<<k<<endl;
    FindSubCloestK(arr, n, k);
}

void FindSubarray0(int arr[], int n){
    vector<int> v;
    v.push_back(0);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        v.push_back(sum);
    }
    //store subarray sum and its ending indices
    unordered_map<int, vector<int> > mapping;
    for(int i = 0; i < v.size(); i++){
        if(mapping.find(v[i]) != mapping.end()){
            for(int j = 0; j < mapping[v[i]].size(); ++j){
                int begin = mapping[v[i]][j];
                Print(arr, begin, i-1);
            }
        }
        mapping[v[i]].push_back(i);
    }
}

/*Find subarray whose sum is closest to K*/
void FindSubCloestK(int arr[], int n, int k){
    vector<pair<int, int> > v;
    v.push_back(make_pair(0,-1));
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        v.push_back(make_pair(sum, i));
    }
    sort(v.begin(),v.end(),Compare);
    cout<<"==========check vector ==========="<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i].first<<" ";
    }
    cout<<endl;
    pair<int, int> result;
    int diff = INT_MAX;
    int p = 0, q = 1;
    while(p < v.size()){
        int j = v[p].second > v[q].second ? v[p].second : v[q].second;
        int i = v[p].second < v[q].second ? v[p].second : v[q].second;
        int sum = v[j+1].first - v[i+1].first;
        if(abs(sum-k) < diff){
            diff = abs(sum - k);
            result = make_pair(i+1, j);
        }
        if(q == v.size()-1){
            p++;
            continue;
        }
        if(sum < k){
            q++;
        }
        else if(sum > k){
            p++;
            if(p == q){
                q++;
            }
        }
        else{
            break;
        }
    }
    Print(arr, result.first, result.second);
}

bool Compare(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

void Print(int arr[], int begin, int end){
    for(int i = begin; i <= end; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}