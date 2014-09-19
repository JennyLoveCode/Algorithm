/*
Problem: Please implement a function which gets the minimal number of coins, whose 
value is v1, v2, …, vn, to make change for an amount of money with value t. Any coin 
with value vi may duplicate for any times to make change.

For example, the minimal number of coins to make change for 15 out of a set of coins 
with value 1, 3, 9, 10 is 3. We can choose two coins with value 3 and a coin with 
value 9. The number of coins for other choices should be greater than 3.
*/
#include <iostream>
#include <vector>
using namespace std;

int MinCount(int , const vector<int> &);

int main(){
    int arr[] = {10, 9, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    const vector<int> coins(arr, arr+n);
    int target =15;
    int result = MinCount(target, coins);
    cout<<result<<endl;
    return 0;
}

int MinCount(int target, const vector<int> &coins){
    vector<int> count(target+1, INT_MAX);
    count[0] = 0;
    for(int i = 1; i <= target; i++){
        int min_count = INT_MAX;
        for(int j = 0; j < coins.size(); j++){
            int value = coins[j];
            if(i - coins[j] >= 0 && count[i - coins[j]] < min_count){
                min_count =count[i - coins[j]];
            }
        }
        if(min_count < INT_MAX){
            count[i] = min_count + 1;
        }
    }
    return count[target];
}