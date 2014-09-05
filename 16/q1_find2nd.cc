/*
Q1 (Array) How to use the least number of comparisons to find the largest and 
second largest number?
*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int winner;
    int loser;
    int idx;
};

int find2nd(vector<int> &arr){
    if(arr.size() <= 1) return -1;
    int const n = arr.size();
    vector<node> v;
    
    int layer = 0;
    int count = 0;
    for(int i = 0; i < n; i += 2){
        node b;
        layer++;
        //In the first layer, node's index doesn't stand for location in vector.
        if (i+1 < n){
            if(arr[i] > arr[i+1]){
                b.winner = arr[i];
                b.loser = arr[i+1];
                b.idx = -1;
            }
            else{
                b.winner = arr[i+1];
                b.loser = arr[i];
                b.idx = -1;
            }
        }
        else{
            b.winner = arr[i];
            b.loser = INT_MIN;
            b.idx = -1;
        }
        v.push_back(b);
        count++;
    }
    
    int start = 0;
    int end = count-1;
    
    while(start < end){
        layer++;
        for(int k = start; k <= end; k += 2){
            node b;
            if(k+1 <= end){
                if(v[k].winner > v[k+1].winner){
                    b.winner = v[k].winner;
                    b.loser = v[k+1].winner;
                    b.idx = k;
                }
                else{
                    b.winner = v[k+1].winner;
                    b.loser = v[k].winner;
                    b.idx = k+1;
                }
            }
            else{
                b.winner = v[k].winner;
                b.loser = v[k].loser;
                b.idx = k;
            }
            v.push_back(b);
            count++;
        }
        start = end+1;
        end = count -1;
    }
    
    int l = layer;
    int second = v[count-1].loser;
    int pre_idx = v[count-1].idx;
    while(l > 0){
        second = max(second, v[pre_idx].loser);
        pre_idx = v[pre_idx].idx;
        l--;
    }

    return second;
}

int main(){
    int a[] = {1,2,4,3,6,100,2,8,99,12,15};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> arr(a, a+n);
    int result = find2nd(arr);
    cout<<result<<endl;
    return 0;
}

/*
Solution:
    Bottom Up, build binary tree and record path.
*/