/*
1. Say you have an array for which the ith element is the price of a given stock 
on day i. If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find 
the maximum profit. Return the indexes that you buy and sell shares.
*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> Stock(vector<int> &);

int main(){
    int arr[] = {1,2,10,50,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> prices(arr, arr+n);
    pair<int,int> result = Stock(prices);
    cout<<"Low price is "<<prices[result.first]<<" High price is "<<prices[result.second]<<endl;
    return 0;
}

pair<int, int> Stock(vector<int> &prices){
    if(prices.size() < 2) return make_pair(-1, -1);
    int cur_min = prices[0];
    int profit = 0;
    int min_so_far = 0;
    int min_ending_here = 0;
    int max_so_far = 1;
    int max_ending_here = 1;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] - cur_min > profit){
            profit = prices[i]-cur_min;
            max_ending_here = i;
        }
        if(prices[i] < cur_min){
            cur_min = prices[i];
            min_ending_here = i;
        }
        if(min_ending_here < max_ending_here){
            min_so_far = min_ending_here;
            max_so_far = max_ending_here;
        }
    }
    return make_pair(min_so_far, max_so_far);
}