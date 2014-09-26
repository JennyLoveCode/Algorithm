/*
Q2: 2D matrix, sorted on each row, first element of next row is larger(or equal) to the 
last element of previous row, now giving a target number, returning the position that 
the target locates within the matrix

0 1 2 3 
4 5 6 7
8 9 10 11

M1: start from top right
M2: binary search
*/
#include <iostream>
#include <vector>
using namespace std;

void Find(vector<vector<int> > , int);

int main(){
    vector<vector<int> > mat;
    int row = 3;
    int col = 4;
    for(int i = 0; i < row; i++){
        vector<int> row;
        for(int j = 0; j < col; j++){
            row.push_back(col*i + j);
        }
        mat.push_back(row);
    }
    int target = 6;
    Find(mat, target);
    return 0;
}

void Find(vector<vector<int> > mat, int target){
    int m = mat.size();
    int n = mat[0].size();
    int left = 0;
    int right = m * n - 1;
    int row = -1;
    int col = -1;
    while(left <= right){
        int mid = left+(right-left)/2;
        row = mid / n;
        col = mid % n;
        if(mat[row][col] == target){
            cout<<"Position is ( "<<row<<" , "<<col<<" ) "<<endl;
            break;
        }
        else if(mat[row][col] < target){
            left = mid+1;
        }
        else{
            right = mid - 1;
        }
    }
}