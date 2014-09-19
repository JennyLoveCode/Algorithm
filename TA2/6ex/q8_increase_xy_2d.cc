/*
8. there are array of 2 dimentional coordinates, find out a line that is x and y 
increasing.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair{
    int x;
    int y;
    Pair(){ }
    Pair(int i, int j):x(i), y(j){ }
};

struct Comparator{
    bool operator() (Pair &a, Pair &b){
        return a.x < b.x;
    }
} cmp;

int FindIncreasePoints(vector<Pair> &);
int LongestSubsequence(vector<int> &);

int main(){
    vector<Pair> v;
    v.push_back(Pair(0,0));
    v.push_back(Pair(1,1));
    //v.push_back(Pair(2,2));
    //v.push_back(Pair(3,3));
    //v.push_back(Pair(4,4));

    v.push_back(Pair(2,1));
    v.push_back(Pair(4,2));
    
    cout<<FindIncreasePoints(v)<<endl;
    return 0;
}

int FindIncreasePoints(vector<Pair> &v){
    sort(v.begin(),v.end(), cmp);
    vector<int> vy;
    for(int i = 0; i < v.size(); i++){
        vy.push_back(v[i].y);
    }
    return LongestSubsequence(vy);
}

int LongestSubsequence(vector<int> &v){
    int result = 0;
    //record maximum length of increasing subsequence ending at index i
    vector<int> len(v.size(), 0);
    for(int i = 0; i < v.size(); i++){
        int max_len = 1;
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                max_len = max(max_len, len[j] + 1);
            }
        }
        len[i] = max_len;
        result = max(result, len[i]);
    }
    return result;
}