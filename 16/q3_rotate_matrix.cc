/*
Q3 OR Q2(b) (Array2) How to rotate an NxN matrix clockwise by 90 degree?
*/
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void print(vector< vector<int> > &matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//valid for square
void rotate(vector< vector<int> > &matrix){
    if(matrix.size() <= 0) return;
    int n = matrix.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
    
    for(int i = 0; i <= n/2; i++){
        for(int j = 0; j < n; j++){
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
}

int main(){
    vector<vector<int> > matrix;
    int n = 5;
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            v.push_back(i*n + j);
        }
        matrix.push_back(v);
    }
    print(matrix);
    rotate(matrix);
    print(matrix);
}