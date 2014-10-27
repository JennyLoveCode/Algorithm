/*
*/
#include <iostream>
#include <vector>
using namespace std;

int StockOne (int arr[], int n);
int StockMany (int arr[], int n);
int StockTwo (int arr[], int n);

int main () {
    int arr[] = {5,3,2,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int res1 = StockOne(arr, n);
    cout<<"res1 is "<<res1<<endl;
    int res2 = StockMany(arr, n);
    cout<<"res2 is "<<res2<<endl;
    int res3 = StockTwo(arr, n);
    cout<<"res3 is "<<res3<<endl;
    return 0;
}

int StockOne (int arr[], int n) {
    if (n < 2) return 0;
    int profit = 0;
    int cur_min = arr[0];
    
    for (int i = 0; i < n; ++i) {
        profit = max(profit, arr[i]-cur_min);
        cur_min = min(cur_min, arr[i]);
    }
    
    return profit;
}

int StockMany (int arr[], int n) {
    if (n < 2) return 0;
    int sum = 0;
    
    for (int i = 1; i < n; ++i) {
        int diff = arr[i] - arr[i-1];
        if (diff > 0) sum += diff;
    }
    return sum;
}

int StockTwo (int arr[], int n) {
    vector<int> first(n, 0);
    vector<int> second(n, 0);
    
    int cur_min = arr[0];
    for (int i = 1; i < n; ++i) {
        first[i] = max(arr[i]-cur_min, first[i-1]);
        cur_min = min(cur_min, arr[i]);
    }
    
    int cur_max = arr[n-1];
    for (int i = n-2; i >= 0; --i) {
        second[i] = max(cur_max-arr[i], second[i+1]);
        cur_max = max(cur_max, arr[i]);
    }
    
    int profit = 0;
    for (int i = 0; i < n; ++i) {
        profit = max(profit, first[i]+second[i]);
    }
    return profit;
}