/*
Q2: (Array2) How Print two dimensional array in an spiral order. （NxN)
*/
#include <iostream>
#include <vector>
using namespace std;

void spiral_print(vector< vector<int> > &matrix){
    int n = matrix.size();
    int beginX = 0;
    int endX = n-1;
    int beginY = 0;
    int endY = n-1;
    
    while(true){
        for(int j = beginX; j <= endX; j++) cout<<matrix[beginY][j]<<" ";
        cout<<endl;
        if(++beginY > endY) break;
        
        for(int i = beginY; i <= endY; i++) cout<<matrix[i][endX]<<" ";
        cout<<endl;
        if(beginX > --endX) break;
        
        for(int j = endX; j >= beginX; j--) cout<<matrix[endY][j]<<" ";
        cout<<endl;
        if(beginY > --endY) break;
        
        for(int i = endY; i >= beginY; i--) cout<<matrix[i][beginX]<<" ";
        cout<<endl;
        if(++beginX > endX) break;
    }
}

int main(){
    vector< vector<int> > matrix;
    int row = 5;
    int col = 5;
    
    for(int i = 0; i < row; i++){
        vector<int> v;
        for(int j = 0; j < col; j++){
            v.push_back(i*col+j);
        }
        matrix.push_back(v);
    }
    
    spiral_print(matrix);
    return 0;
}