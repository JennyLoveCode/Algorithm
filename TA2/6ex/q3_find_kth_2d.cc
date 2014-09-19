/*
3. find kth largest element
1  2  3  4   5
2  3  4  5   6
3  4  5  6   7
4  5  6  7   8
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int val;
    int x;
    int y;
    Node(){ }
    Node(int v, int i, int j):val(v), x(i), y(j){ }
    bool operator > (const Node &other) const{
        return val > other.val; 
    }
};

int FindKth(int mat[][5], int , int , int);

int main(){
    int mat[][5] ={
    {1,2,3,4,5},
    {2,3,4,5,6},
    {3,4,5,6,7},
    {4,5,6,7,8}  
    };
    
    int k = 20;
    int result = FindKth(mat, k, 4, 5);
    cout<<result<<endl;
    return 0;
}

int FindKth(int mat[][5], int k, int m, int n){
    priority_queue<Node, vector<Node>, greater<Node> > heap;
    heap.push(Node(mat[0][0],0,0));
    vector<bool> visited(m*n, false);
    visited[0] = true;
    int count = 0;
    int result;
    while(!heap.empty()){
        Node cur = heap.top();
        cout<<count<<"th value is "<<cur.val<<endl;
        heap.pop();
        if(++count == k){
            result = cur.val;
            break;
        }
        int i = cur.x;
        int j = cur.y;
        if(i+1 < m && visited[(i+1)*n + j] == false){
            heap.push(Node(mat[i+1][j], i+1, j)); 
            visited[(i+1)*n + j] = true;       
        }
        if(j+1 < n && visited[i*n + j+1] == false){
           heap.push(Node(mat[i][j+1], i, j+1));  
           visited[i*n+j+1] = true;       
        }
    }
    return result;
}