/*
matrix reverse 90 degree with reverse counter.
		1 2 3 4			->	4 8 12 16
		5 6 7 8				3 7 11 15
		9 10 11 12			2 6 10 14
		13 14 15 16			1 5 9 13
*/
#include <iostream>
#include <vector>
using namespace std;

void Rotate (vector<vector<int> > &mat);
void print (vector<vector<int> > &mat);
void swap (int &a, int &b);

int main () {
    int n = 4;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    int num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = num;
            ++num;
        }
    }
    print(mat);
    cout<<"-----------"<<endl;
    Rotate(mat);
    print(mat);
    return 0;
}

void Rotate (vector<vector<int> > &mat) {
    int n = mat.size();
    //reverse according to principle diagonal
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    //reverse 
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(mat[i][j], mat[n-1-i][j]);
        }
    }
}

void print (vector<vector<int> > &mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void swap (int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}