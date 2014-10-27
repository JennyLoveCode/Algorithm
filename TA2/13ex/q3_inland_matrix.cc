/*
Find the number of inland in a matrix
	1   1   1   1   1   1 
	1   0   0   1   1   1
	1   1   1   0   0   1
	1   1   1   1   1   1
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int val;
    int i;
    int j;
    Node () { }
    ~Node () { }
    Node (int v, int x, int y) : val(v), i(x), j(y){ }
};

int Inland (int arr[][6], int m, int n);

int main () {
    int arr[][6] = {
                    {1,1,1,1,1,1},
                    {1,0,0,1,1,1},
                    {1,1,1,0,0,1},
                    {1,1,1,1,1,1},
                    };
    int m = 4;
    int n = 6;
    int res = Inland(arr, m, n);
    cout<<res<<endl;
    return 0;
}

int Inland (int arr[][6], int m, int n) {
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    int count = 0;
    bool flag = true; //no 0 in surrounding sides
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j] == 0 && visited[i][j] == false) {
                visited[i][j] = true;
                queue<Node> q;
                q.push(Node(arr[i][j], i, j));
                flag = true;
                while (!q.empty()) {
                    Node cur = q.front();
                    q.pop();
                    if (cur.i == 0 || cur.j == 0) {
                        flag = false;
                    }
                    if (i+1 < m && arr[i+1][j] == 0 && visited[i+1][j] == false) {
                        q.push(Node(arr[i+1][j], i+1, j));
                        visited[i+1][j] = true;
                    }
                    if (j+1 < n && arr[i][j+1] == 0 && visited[i][j+1] == false) { 
                        q.push(Node(arr[i][j+1], i, j+1));
                        visited[i][j+1] = true;
                    }
                }
                if(flag){
                    ++count;
                }
            }
            visited[i][j] = true;
        }
    }
    return count;
}