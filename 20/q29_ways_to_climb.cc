/*
Q29 一个人从山下走上n个台阶，每步可以迈1，2，或者3个台阶，请问有多少种走法？
*/
#include <iostream>
#include <vector>
using namespace std;

int DiffWays(int);

int main(){
    int n = 4;
    int result = DiffWays(n);
    cout<<result<<endl;
    return 0;
}

int DiffWays(int n){
    vector<int> count(n+1, 0);
    //base case
    count[1] = 1;
    count[2] = 2;
    count[3] = 4;
    if(n <= 3) return count[n];

    for(int i = 4; i <= n; i++){
        count[i] = count[i-1]+count[i-2]+count[i-3];
    }
    return count[n];
}