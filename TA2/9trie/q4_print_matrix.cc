/* 
4. print matrix dianostically.
1    2   3  4   5
6    7   8  9  10
11  12  13  14 15
=>
1
6 2
11 7 3
12 8 4
13 9 5
14 10
15
*/

#include <iostream>
#include <vector>
using namespace std;

void Print(vector<vector<int> > );

int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {6,7,8,9,10};
    int c[] = {11,12,13,14,15};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    int n3 = sizeof(c)/sizeof(c[0]);
    vector<int> v1(a, a+n1);
    vector<int> v2(b, b+n2);
    vector<int> v3(c, c+n3);
    vector<vector<int> > mat;
    mat.push_back(v1);
    mat.push_back(v2);
    mat.push_back(v3);
    
    Print(mat);
    return 0;  
}

void Print(vector<vector<int> > mat){
    int row = mat.size();
    int col = mat[0].size();
    
    //k means step
    for(int k = 0; k < row+col; ++k){
        //the coordinates of first element in each level
        int i = k;
        int j = 0;
        if(k >= row){
            i = row-1;
            j = k - row;
        }
        while(i >=0 && i < row && j < col){
            cout<<mat[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
}
