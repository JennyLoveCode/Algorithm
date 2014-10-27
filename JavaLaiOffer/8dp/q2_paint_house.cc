/*
Paint house:
minimize the cost of painting K houses, each house has different costs to paint in 
different colors, 2 houses (next to each other) cannot be painted in the same color.

Example, 4 houses(1,2,3,4) & 3 colors(R,G,B)
    1   2   3   4
R   10  30  15  5
G   15  10  5   30
B   20  15  50  20
*/

#include <iostream>
#include <vector>
using namespace std;

int PaintHouse (int cost[][4], int m, int n);

int main () {
    int cost[][4] = {
                    {10,30,15,5},
                    {15,10,5,30},
                    {20,15,50,20}
    };
    int m = 3;
    int n = 4;
    int res = PaintHouse(cost, m, n);
    cout<<"cost is "<<res<<endl;
    return 0;
}

//state[X][idx] indicates the cost of painting house j in X color
//state[X][idx] = min(state[i][idx-1])+cost[X][idx] (i!=X)
//return min(state[i][4]) i includes all colors

int PaintHouse (int cost[][4], int m, int n) {
    vector<vector<int> > state(m, vector<int>(n, INT_MAX));
    for(int color = 0; color < m; ++color){
        state[color][0] = cost[color][0];
    }
    
    for (int idx = 1; idx < n; ++idx) {
        for (int color = 0; color < m; ++color) {
            for (int i = 0 ; i < m; ++i) {
                if (i == color) {
                    continue;
                }
                if(state[i][idx-1] < state[color][idx]){
                    state[color][idx] = state[i][idx-1];
                }
            }
            state[color][idx] += cost[color][idx];
        }
    }
    
    int result = INT_MAX;
    for(int color = 0; color < m; ++color){
        result = min(result, state[color][n-1]);
    }
    return result;
}

/*
N casino 30 day max profit, 每个赌场每天的盈利情况不一样，每天只能在一个赌场，第二天只能跳跃到相邻
的赌场

state[day][casino] = max(state[day-1][casino-1],state[day-1][casino+1]) + profit[day][casino]
result = max(state[30][casino]) casino from 1 to N
*/