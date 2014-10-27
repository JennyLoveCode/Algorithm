/*
Array of integers. exists i, j, k? such that i < j < k && array[i] < array[j] < array[k]
*/
#include <iostream>
#include <vector>
using namespace std;

bool Check (int arr[], int n);
int Count (int arr[], int n);
void print(vector<int> &v);

int main () {
    int arr[] = {10, 1, 4, 2, 8, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool res = Check(arr, n);
    if (res) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
    int count = Count(arr, n);
    cout<<"count is "<<count<<endl;
    return 0;
}

bool Check (int arr[], int n) {
    vector<int> small(n, arr[0]);
    vector<int> large(n, arr[n-1]);
    
    for (int i = 1;  i < n; ++i) {
        small[i] = min(arr[i], small[i-1]);
        large[n-i-1] = max(arr[n-i], large[n-i-1]);
    }
    
    for(int i = 0; i < n; ++i){
        if(arr[i] != small[i] && arr[i] != large[i]){
            return true;
        }
    }
    
    return false;
}

/*
array of integers. how many (i, j, k) triples? such that i < j < k && array[i] < array[j] < array[k]
*/

int Count (int arr[], int n) {
    vector<int> small(n, 0);
    vector<int> large(n, 0);
    
    for (int i = 1; i < n; ++i) {
        int cur = 0;
        for(int j = 0; j < i; ++j){
            if (arr[j] < arr[i]) {
                ++cur;
            }
        }
        small[i] = cur;
    }
    
    for (int i = n-2; i >= 0; --i) {
        int cur = 0;
        for (int j = n-1; j > i; --j) {
            if (arr[j] > arr[i]) {
                ++cur;
            }
        }
        large[i] = cur;
    }
    
    print(small);
    print(large);
    
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += small[i]*large[i];
    }
    return result;
}

void print(vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}