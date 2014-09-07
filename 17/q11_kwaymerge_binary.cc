/*
Q11: k way merge: How to merge k sorted array into one big sorted array?
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> k_way_merge(vector< vector<int> > &);
vector<int> merge_help(vector<int> &, vector<int> &);
void print(vector<int> &);

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
    while(arrays.size() > 1){
        vector< vector<int> > tmp;
        if(arrays.size() % 2 == 1){
            arrays.push_back(vector<int>());
        }
        for(int i = 0; i < arrays.size(); i += 2){
            vector<int> intermedium = merge_help(arrays[i],arrays[i+1]);
            tmp.push_back(intermedium);
        }
        arrays = tmp;
    }
    return arrays[0];
}

vector<int> merge_help(vector<int> &a, vector<int> &b){
    if(a.empty()) return b;
    if(b.empty()) return a;
    int i = 0;
    int j = 0;
    vector<int> merged;
    
    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }
    
    for(; i < a.size(); i++){
        merged.push_back(a[i]);
    }
    
    for(; j < b.size(); j++){
        merged.push_back(b[j]);
    }
    
    return merged;
}

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
