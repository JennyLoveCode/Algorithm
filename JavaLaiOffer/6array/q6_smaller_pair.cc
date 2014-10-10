/*
One unsorted array no duplicate values, find
1). number of all pairs, 
2) all pairs that the sum of the two numbers is greater/smaller 
than a given number k.

Example:
A = {3, 1, 4, 2, 5, 9}
k = 7
pairs = (3, 1), (3, 2), (1, 4), (1, 2), (1, 5), (4, 2)
# of pairs = 6
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int> > Pairs(vector<int> v, int k);
void Print(vector<pair<int, int> > &v);

int main(){
    int arr[] = {3,1,4,2,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    int k = 7;
    vector<pair<int,int> > result = Pairs(v,k);
    cout<<"# of pairs = "<<result.size()<<endl;
    cout<<"pairs are "<<endl;
    Print(result);
    return 0;
}

vector<pair<int,int> > Pairs(vector<int> v, int k){
    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size()-1;
    bool flag = false; //indicate whether j moves
    vector<pair<int, int> > res;
    
    while(i < j){
        if(v[i]+v[j] < k){
            //push pair at index i and j
            res.push_back(make_pair(v[i], v[j]));
            //push pairs in the left of i
            for(int t = 0; t < i; ++t){
                res.push_back(make_pair(v[t],v[i]));
            }
            //check whether j is updated in previous step
            if(flag){
                for(int t = 0; t < i; ++t){
                    res.push_back(make_pair(v[t],v[j])); 
                }
            }
            ++i;
        }
        else{
            flag = true;
            --j;
        }
    }
    
    //last pairs maybe
    if(i-1 >= 0 && v[i-1]+v[i] < k){
        res.push_back(make_pair(v[i-1], v[i]));
        if(flag){
            for(int t = 0; t < i-1; ++t){
                res.push_back(make_pair(v[t],v[i]));
            }
        }
    }
    return res;
}

void Print(vector<pair<int, int> > &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<"("<<v[i].first<<","<<v[i].second<<") ";
    }
    cout<<endl;
}