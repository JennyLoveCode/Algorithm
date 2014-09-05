/*
Q10: (Array+Recursion) 8queen question
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* abs */
using namespace std;

void queens(vector< vector<string> > &, int);
void helper(vector< vector<string> > &, vector<int> &, int, int);
bool valid(vector<int> &, int, int);
void print(vector< vector<string> > &, int);

int main(){
    int n = 8;
    vector< vector<string> > result;
    queens(result, n);
    print(result, n);
    cout<<result.size()<<endl;
}

void queens(vector< vector<string> > &result, int n){
    vector<int> state(n, -1);
    helper(result,state, n, 0);
}

void helper(vector< vector<string> > &result, vector<int> &state, int n, int row){
    //base case
    if(row == n){
        vector<string> solution(n, string(n, '.'));
        for(int i = 0; i < n; i++){
            solution[i][state[i]] = 'Q';
        }
        result.push_back(solution);
        return;
    }
    //recursive rule
    for(int col = 0; col < n; col++){
        if(valid(state, row, col)){
            state[row] = col;
            helper(result, state, n, row+1);
            state[row] = -1;
        }
    }
}

bool valid(vector<int> &state, int row, int col){
    for(int i = 0; i < row; i++){
        if(state[i] == col || abs(row - i) == abs(col - state[i])){
            return false;
        }
    }
    return true;
}

void print(vector< vector<string> > &result, int n){
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < n; j++){
            cout<<result[i][j]<<endl;
        }
        cout<<"========================="<<endl;
    }
}

/*
其实只需要用一个一位数组来存放当前皇后的状态。假设数组为int state[n], 
state[i]表示第 i 行皇后所在的列。那么在新的一行 k 放置一个皇后后:
判断列是否冲突，只需要看state数组中state[0…k-1] 是否有和state[k]相等；
判断对角线是否冲突：如果两个皇后在同一对角线，那么|row1-row2| = |column1 - column2|，
（row1，column1），（row2，column2）分别为冲突的两个皇后的位置
*/