/*
Q28 (recursion) 有1 分， 5分， 10分，25分coin， 给定一个钱数99 , 有多少种组成方式,
并打印出所有的可能组合？
*/
#include <iostream>
#include <vector>
using namespace std;

void Combinations(int , int , vector<int> &, const vector<int> &);

int main(){
    int arr[] = {25, 10, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    const vector<int> coin(arr, arr+n);
    int cur = 26;
    vector<int> solution(n, -1);
    Combinations(cur, 0, solution,coin);
    return 0;
}

void Combinations(int cur, int idx, vector<int> &solution, const vector<int> &coin){
    int n = coin.size();
    if(idx == n){
        if(cur == 0){
            for(int i = 0; i < n; i++){
                cout<<solution[i]<<"*"<<coin[i]<<"+";
            }
            cout<<endl;
        } 
        return;
    }
    for(int i = 0; i*coin[idx] <= cur; i++){
        solution[idx] = i;
        Combinations(cur-i*coin[idx], idx+1, solution, coin);
    }
}