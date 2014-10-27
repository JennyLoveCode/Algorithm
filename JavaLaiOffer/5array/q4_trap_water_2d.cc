/*
trapping rain water 2-d array

4   5   6    5
3   2   1    7
8   4   2    8
5   6   3    3

*/
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

struct Node{
    int val;
    int x;
    int y;
    Node(){}
    ~Node(){}
    Node(int v, int i, int j): val(v), x(i), y(j){ }
    
    bool operator > (const Node &other) const{
        return  val > other.val;
    }
};

int MostWater(int arr[][6], int m, int n);
void Traverse(int arr[][6], vector<vector<bool> > &visited, int i, int j, Node wall, int &water, queue<Node> &q, priority_queue<Node, vector<Node>, greater<Node> > &heap);
bool isValid(vector<vector<bool> > &visited, int i, int j);

int main(){
    int arr[][6] = { {4,5,6,5,5,5},
                     {3,2,1,1,1,7},
                     {8,9,9,9,9,8},
                     {8,9,1,9,9,8},
                     {5,9,9,9,3,3}
    };
    int m = 5, n =6;
    int res = MostWater(arr, m, n);
    cout<<res<<endl;
    return 0;
}

int MostWater(int arr[][6], int m, int n){
    //put surrounding elements into heap
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    vector<Node> v;
    for(int j = 0; j < n; ++j){
        v.push_back(Node(arr[0][j],0,j));
        visited[0][j] = true;
        v.push_back(Node(arr[m-1][j],m-1,j));
        visited[m-1][j] = true;
    }
    for(int i = 1; i < n-1; ++i){
        v.push_back(Node(arr[i][0],i,0));
        visited[i][0] = true;
        v.push_back(Node(arr[i][n-1],i, n-1));
        visited[i][n-1] = true;
    }
    priority_queue<Node, vector<Node>, greater<Node> > heap(v.begin(), v.end());
    queue<Node> q;
    int water = 0;
    
    while (!heap.empty()) {
        Node wall = heap.top();
        int i = wall.x;
        int j = wall.y;
        heap.pop();
        //BFS
        Traverse(arr, visited, i, j, wall, water, q, heap);

        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            int i = cur.x;
            int j = cur.y;
            //BFS
            Traverse(arr, visited, i, j, wall, water, q, heap);
        }
    }
    return water;
}

void Traverse(int arr[][6], vector<vector<bool> > &visited, int i, int j, Node wall, int &water, queue<Node> &q, priority_queue<Node, vector<Node>, greater<Node> > &heap) {
    //up
    if(isValid(visited, i-1, j)){
        visited[i-1][j] = true;
        if(arr[i-1][j] < wall.val){
            water += wall.val-arr[i-1][j];
            q.push(Node(arr[i-1][j], i-1, j));
        } else {
            heap.push(Node(arr[i-1][j], i-1, j));
        }
    }
    //down
    if(isValid(visited, i+1, j)){
        visited[i+1][j] = true;
        if(arr[i+1][j] < wall.val){
            water += wall.val-arr[i+1][j];
            q.push(Node(arr[i+1][j], i+1, j));
        } else {
            heap.push(Node(arr[i+1][j], i+1, j));
        }
    }
    //left
    if(isValid(visited, i, j-1)){
        visited[i][j-1] = true;
        if(arr[i][j-1] < wall.val){
            water += wall.val-arr[i][j-1];
            q.push(Node(arr[i][j-1], i, j-1));
        } else {
            heap.push(Node(arr[i][j-1], i, j-1));
        }
    }
    //right
    if(isValid(visited, i, j+1)){
        visited[i][j+1] = true;
        if(arr[i][j+1] < wall.val){
            water += wall.val-arr[i][j+1];
            q.push(Node(arr[i][j+1], i, j+1));
        } else {
            heap.push(Node(arr[i][j+1], i, j+1));
        }
    }
}              

bool isValid(vector<vector<bool> > &visited, int i, int j){
    int m = visited.size();
    int n = visited[0].size();
    if(i >=0 && i < m && j>=0 &&j < n && visited[i][j] == false){
        return true;
    }
    return false;
}

/*
while (heap is not empty) {
    min heap maintain the current minimum height.
    get the min from the heap, DFS/BFS.
    insert 4 to the heap.
}
*/