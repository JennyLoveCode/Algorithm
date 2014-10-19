/*
 Giving a matrix, print them in spiral order.
*/
#include <iostream>
using namespace std;

void Print(int mat[][3], int k, int row, int col);

int main(){
    int mat[4][3] = {
                    {1,2,3},
                    {4,5,6},
                    {7,8,9},
                    {10,11,12},
    };
    Print(mat,0,4,3);
    return 0;
}

void Print(int mat[][3], int k, int row, int col){
    //base case
    if(row ==0 && col == 0){
        return;
    }
    if(row == 1 && col == 1){
        cout<<mat[k][k]<<endl;
        return;
    }
    if(row == 1 && col > 1){
        for(int j = k; j < k+col; ++j){
            cout<<mat[k][j]<<" ";
        }
        cout<<endl;
        return;
    }
    if(col == 1 && row > 1){
        for(int i = k; i < k+row; ++i){
            cout<<mat[i][k]<<" ";
        }
        cout<<endl;
        return;
    }

    //from left to right
    for(int j = k; j < k+col; ++j){
        cout<<mat[k][j]<<" ";
    }
    cout<<endl;
    //from top to bottom
    for(int i = k+1; i < k+row; ++i){
        cout<<mat[i][k+col-1]<<" ";
    }
    cout<<endl;
    //from right to left
    for(int j = k+col-2; j >= k; --j){
        cout<<mat[k+row-1][j]<<" ";
    }
    cout<<endl;
    //from bottom to top
    for(int i = k+row-2; i >= k+1; --i){
        cout<<mat[i][k]<<" ";
    }
    cout<<endl;
    
    //recursive rule
    Print(mat, k+1, row-2, col-2 );
}