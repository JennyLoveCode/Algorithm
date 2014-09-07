/*
Q11: k way merge: How to merge k sorted array into one big sorted array?
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> k_way_merge(vector< vector<int> > &);
void print(vector<int> &);

struct node{
    int val;
    int array_idx;
    
    node(){}
    node(int v, int idx):val(v), array_idx(idx){}
    
    bool operator>(const node &other) const{
        return val > other.val;
    }
};

int main(){
    int a[] = {1,3,5};
    int b[] = {2,4,6};
    int c[] = {5,6,7,8};
    vector<int> v1 (a, a + sizeof(a)/sizeof(a[0]));
    vector<int> v2 (b, b + sizeof(a)/sizeof(b[0]));
    vector<int> v3 (c, c + sizeof(a)/sizeof(c[0]));
    vector< vector<int> > arrays;
    arrays.push_back(v1);
    arrays.push_back(v2);
    arrays.push_back(v3);

    vector<int> result = k_way_merge(arrays);
    print(result);
    return 0;
}

vector<int> k_way_merge(vector< vector<int> > &arrays){
    int k = arrays.size();
    //store index of next element to push into heap in each array
    vector<int> index(k, 0); 
    vector<int> solution;
    priority_queue<node, vector<node>, greater<node> > minheap;
    
    for(int i = 0; i < k; i++){
        minheap.push(node(arrays[i][0], i));
        index[i]++;
    }
    
    while(!minheap.empty()){
        node cur = minheap.top();
        minheap.pop();
        solution.push_back(cur.val);
        if(index[cur.array_idx] < arrays[cur.array_idx].size()){
            int next = index[cur.array_idx];
            int v = arrays[cur.array_idx][next];
            minheap.push(node(v, cur.array_idx));
            index[cur.array_idx]++;         
        }
    }
    
    return solution;
}

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}