/*
Find a path from  entry [0, 0] to exit.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool FindPath(vector<string> &matrix);
bool FindPathHelp(vector<string> &matrix, int row, int col, int i, int j,vector<string> &visited);

int main(){
    string arr[] = {
    "00000",
    "11110",
    "11000",
    "11011",
    "11000"};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<string> matrix(arr, arr+n);
    bool result = FindPath(matrix);

    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

bool FindPath(vector<string> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<string> visited;
    for(int i = 0; i < m; ++i){
        string s(n, '0');
        visited.push_back(s);
    }
    return FindPathHelp(matrix, m, n, 0, 0, visited);
}

bool FindPathHelp(vector<string> &matrix, int row, int col, int i, int j, vector<string> &visited){
    //base case: exceed boundary
    cout<<"i "<<i<<" j "<<j<<endl;
    if(i < 0 || i >= row || j < 0 || j >= col){
        return false;
    }
    //meet obstacle
    if(matrix[i][j] == '1'){
        return false;
    }
    //arrive exit point
    if(i == row -1 && j == col-1){
        return true;
    }
    //check dead loop
    if(visited[i][j] == '1'){
        return false;
    }
    visited[i][j] = '1';
    //recursive rule : move towards four directions
    bool up = FindPathHelp(matrix, row, col, i-1, j, visited);
    bool down = FindPathHelp(matrix, row, col, i+1, j, visited);
    bool right = FindPathHelp(matrix, row, col, i, j+1, visited);
    bool left = FindPathHelp(matrix, row, col, i, j-1,visited);
    visited[i][j] = '0';
    return up || down || right ||left;
}