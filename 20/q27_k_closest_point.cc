/*
Q27 Given three arrays with numbers in ascending order. Pull one number from each array to
form a coordinate <x,y,z> in a 3D space. (1) How to find the coordinates of the points that 
is k-th closest to <0,0,0>?
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

struct Point{
    //value in the direction X, Y, Z
    int x;
    int y;
    int z;
    //index in the array
    int i;
    int j;
    int k;
    Point(){ }
    Point(int _x, int _y, int _z, int _i, int _j, int _k):
    x(_x), y(_y),z(_z), i(_i), j(_j),k(_k){ }

    bool operator > (const Point &other) const{
        return x*x+y*y+z*z > other.x*other.x+other.y*other.y+other.z*other.z;
    }
};

Point KthClosest(vector<int> &, vector<int> &, vector<int> &, int );

int main(){
    int xarr[] = {9,5,6,3,7};
    int yarr[] = {2,8,4,5,1};
    int zarr[] = {1,3,2,5,6};
    vector<int> x(xarr, xarr+5);
    vector<int> y(yarr, yarr+5);
    vector<int> z(zarr, zarr+5);
    
    for(int k = 1; k < 50; k++){
        Point result = KthClosest(x,y,z,k);
        int dist = result.x*result.x + result.y*result.y + result.z*result.z;
        cout<<k<<" "<<dist<<" x "<<result.x<<" y "<<result.y<<" z "<<result.z<<endl;
    }
    cout<<endl;
    return 0;   
}

Point KthClosest(vector<int> &X, vector<int> &Y, vector<int> &Z, int k){
    //sort array in ascending order
    sort(X.begin(), X.end(), less<int>());
    sort(Y.begin(), Y.end(), less<int>());
    sort(Z.begin(), Z.end(), less<int>());
    //min heap
    priority_queue<Point,vector<Point>, greater<Point> > q;
    q.push(Point(X[0],Y[0],Z[0],0,0,0));
    vector<vector<vector<bool> > > visited(X.size(), vector<vector<bool> >(Y.size(), vector<bool>(Z.size(), false)));
    visited[0][0][0] = true;

    int count = k;
    while(!q.empty()){
        Point cur = q.top();
        q.pop();
        count--;
        if(count == 0){
            return cur;
        }
        int i = cur.i;
        int j = cur.j;
        int k = cur.k;
        int x = cur.x;
        int y = cur.y;
        int z = cur.z;
        if(i+1 < X.size() &&  visited[i+1][j][k] == false){
            q.push(Point(X[i+1],y,z,i+1,j,k));
            visited[i+1][j][k] = true;
        }
        if(j+1 < Y.size() && visited[i][j+1][k] == false){
            q.push(Point(x,Y[j+1],z,i,j+1,k));
            visited[i][j+1][k] = true;
        } 
        if(k+1 < Z.size() && visited[i][j][k+1] == false){
            q.push(Point(x,y,Z[k+1],i,j,k+1));
            visited[i][j][k+1] = true;
        } 
    }
    cout<<"Cannot find "<<k<<"th point."<<endl;
    return Point(-1,-1,-1,-1,-1,-1);   
}