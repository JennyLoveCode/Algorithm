/*
n queen problem
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Queen (int n, vector<int> &state, int row);
bool isValid (vector<int> &state, int row, int col);
void print (vector<string> &v);

int main () {
    int n = 5;
    vector<int> state(n, -1);
    Queen(n, state, 0);
    return 0;
}

void Queen (int n, vector<int> &state, int row) {
    //base case
    if (row == n) {
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            int j = state[i];
            solution[i][j] = 'Q';
        }
        print(solution);
        return;
    }
    //DFS
    for (int j = 0; j < n; ++j) {
        if (isValid(state, row, j)) {
            state[row] = j;
            Queen(n, state, row+1);
            state[row] = -1;
        }
    }
}

bool isValid (vector<int> &state, int row, int col) {
    for (int i = 0;  i < row; ++i) {
        //not same col
        if (state[i] == col) {
            return false;
        }
        //not diagonal
        if (abs(state[i]-col) == abs(i-row)) {
            return false;
        }
    }
    return true;
}

void print (vector<string> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    cout<<endl;
}