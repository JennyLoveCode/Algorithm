/*
Q24, Given a gym with k equipments, and some obstacles. Let’s say we bought a chair and
want to put this chair into the gym such that the sum of the shortest path from the chair 
to the k equipments are minimal.
n x n space
k equipments
1 chair
xxxxexxxxxxx
xcxxxxxexxxx
xxxxexxxxxxx
xxxxxxxxxxxx
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef struct Point{
    int x, y;
    Point(){ }
    Point(int i, int j): x(i), y(j){ }
}Point;

//four directions in BFS
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

Point ShortestPath(vector<string> &);
void BFS(Point, vector<string> &, vector<vector<int> > &);
bool IsValid(Point,vector<string> &, vector<vector<int> > &);

int main(){
    string r1 = "...E.";
    string r2 = ".O...";
    string r3 = "EO..O";
    string r4 = "...OE";
    string r5 = ".E...";
    vector<string> gym;
    gym.push_back(r1);
    gym.push_back(r2);
    gym.push_back(r3);
    gym.push_back(r4);
    gym.push_back(r5);

    Point result = ShortestPath(gym);
    cout<<"x is "<<result.x<<" y is "<<result.y<<endl;
    return 0;
}

Point ShortestPath(vector<string> &gym){
    int n = gym.size();
    
    vector<vector<vector<int> > > record;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(gym[i][j] == 'E'){
                Point start(i, j);
                vector<vector<int> > dist(n, vector<int>(n, 0));
                BFS(start, gym, dist);
                record.push_back(dist);
            }
        }
    }
    
    Point best;
    int shortest_path = INT_MAX;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(gym[i][j] == 'E' || gym[i][j] == 'O'){
                continue;
            }
            int sum = 0;
            for(int k = 0; k < record.size(); k++){
                sum += record[k][i][j];
            }
            if(sum < shortest_path){
                shortest_path = sum;
                best = Point(i, j);
            }
        }
    }
    return best;
}

void BFS(Point start, vector<string> &gym, vector<vector<int> > &dist){
    queue<Point> q;
    q.push(start);
    while(!q.empty()){
        Point cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            Point next(cur.x+dx[i], cur.y+dy[i]);
            if(IsValid(next, gym, dist)){
                q.push(next);
                dist[next.x][next.y] = dist[cur.x][cur.y] + 1;
            }
        }
    }
}

bool IsValid(Point next, vector<string> &gym, vector<vector<int> > &dist){
    int i = next.x;
    int j = next.y;
    //out of gym scope
    if(i < 0 || i >= gym.size() || j < 0 || j >= gym[0].size()){
        return false;
    }
    //equipment or obstacle
    if(gym[i][j] == 'E' || gym[i][j] == 'O'){
        return false;
    }
    //visited or not
    return dist[i][j] == 0;
}