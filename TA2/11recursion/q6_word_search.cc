/*
Judge whether a word exists in a matrix
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool WordSearch(vector<string> matrix, string target);
bool WordSearchHelp(vector<string> matrix, int m, int n, string target, int cur, int i, int j);

int main(){
    string arr[] = {
    "abcde",
    "paace",
    "alebb",
    "ccccc"};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<string> matrix(arr, arr+n);
    
    string target = "apple";
    bool result = WordSearch(matrix, target);
    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

bool WordSearch(vector<string> matrix, string target){
    int m = matrix.size();
    int n = matrix[0].size();
    return WordSearchHelp(matrix, m, n, target, 0, 0, 0);
}

bool WordSearchHelp(vector<string> matrix, int m, int n, string target, int cur, int i, int j){
    //base case
    if(cur == target.size()){
        return true;
    }
    if(i < 0 || i >= m || j < 0 || j>= n){
        return false;   
    }
    if(matrix[i][j] != target[cur]){
        return false;
    }
    //check dead loop : take reference with q5 maze path
    return WordSearchHelp(matrix, m, n, target, cur+1, i+1, j)
            || WordSearchHelp(matrix, m, n, target, cur+1, i-1, j)
            || WordSearchHelp(matrix, m, n, target, cur+1, i, j+1)
            || WordSearchHelp(matrix, m, n, target, cur+1, i, j-1);
}