/*
largest subarray product
{1, -3, 1, 3, -5} → 1 * -3 * 1 * 3 * -5 = 45
*/
#include <iostream>
#include <vector>
using namespace std;

int MaxProduct (vector<int> v);
int min(int a, int b, int c);
int max(int a, int b, int c);

int main () {
    int arr[] = {1, -3, 1, 3, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int res = MaxProduct(v);
    cout<<res<<endl;
    return 0;
}

//stateMax  stateMin
int MaxProduct (vector<int> v) {
    int n = v.size();
    vector<int> stateMin; //stateMin[i]: min product ending at index i
    vector<int> stateMax; //stateMax[i]: max product ending at index i
    
    int result = v[0];
    stateMin.push_back(v[0]);
    stateMax.push_back(v[0]);
    for (int i = 1; i < n; ++i) {
        int minP = min(stateMin[i-1]*v[i], stateMax[i-1]*v[i], v[i]);
        stateMin.push_back(minP);
        int maxP = max(stateMin[i-1]*v[i], stateMax[i-1]*v[i], v[i]);
        stateMax.push_back(maxP);
        result = max(result, stateMax[i]);
    }
    return result;
}

int min(int a, int b, int c){
    int t = min(a, b);
    return min(t, c);
}

int max(int a, int b, int c){
    int t = max(a, b);
    return max(t, c);
}