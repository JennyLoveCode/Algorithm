/*
    0   1   2   3   4
0   ff  tf  tf  tf  tf
1   ft  tf  tt  tt  tt
2   ft  tt  tt  tt  tt
3   ft  ft  tt  tt  ft
4   ft  tf  tt  tt  tt
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    bool left;
    bool up;
    int max_left;
    int max_up;
    
    Node () { }
    ~Node () { }
    Node (bool l, bool u) : left(l), up(u), max_left(0), max_up(0){ }
};

int CountSquares (vector<string> left, vector<string> up);

int main () {
    string arr_left[] ={"ftttt",
                        "ftttt",
                        "ftttt",
                        "ffttf",
                        "ftttt"
                    }; 
    string arr_up[] = { "fffff",
                        "tfttt",
                        "ttttt",
                        "ttttt",
                        "tfttt"
                    };
    int n = sizeof(arr_up)/sizeof(arr_up[0]);
    vector<string> left(arr_left, arr_left+n);
    vector<string> up(arr_up, arr_up+n);
    int res = CountSquares(left, up);
    cout<<res<<endl;
    return 0;
}

int CountSquares (vector<string> left, vector<string> up) {
    int m = left.size();
    int n = left[0].size();
    vector<vector<Node> > matrix;
    int result = 0;

    //build matrix and update result
    for (int i = 0; i < m; ++i) {
        vector<Node> row;
        matrix.push_back(row);
        for (int j = 0; j < n; ++j) {
            Node cur(false, false);

            //update left of node
            if (j-1 >= 0 && left[i][j] == 't') {
                cur.left = true;
                cur.max_left = matrix[i][j-1].max_left+1;
            }

            //update up of node
            if (i-1 >= 0 && up[i][j] == 't'){
                cur.up = true;
                cur.max_up= matrix[i-1][j].max_up+1;
            }

            //push node to matrix
            matrix[i].push_back(cur);

            //count squares: take (i, j) as the right bottom point in available squares
            for (int len = min(cur.max_up, cur.max_left); len > 0; --len) {
                //check whether one side exists
                if (i-len >= 0 && matrix[i-len][j].max_left >= len) {
                    //check whether another side exist
                    if (j-len >= 0 && matrix[i][j-len].max_up >= len) {
                        ++result;
                    }
                }
            }
        }
    }
    return result;
}