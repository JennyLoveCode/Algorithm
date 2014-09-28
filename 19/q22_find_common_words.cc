/*
Q22 给一个list of sentences, 然后找出一个pair of sentences, 使得common words 最多。
Example:
1.1. This is a good day 5 --> 3 65 1 77 78
1.2. This is a bad day 5 --> 3 65 1 76 78
1.3. That was good day 4
1.4. apple
n sentence, average size of sentence is m word, the size of each word is k.
返回1和2，因为有四个common words
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

struct pair_hash{
    inline int operator() (const pair<int,int> &p ) const{
        return p.first*31+p.second;
    }
};

vector<int> CommonWords(vector<vector<string> > &);
int CompareWords(vector<string> &, vector<string> &);
bool compare(vector<string> &, vector<string> &);
void Swap(int &, int &);
void Print(vector<string> &);

int main(){
    string a[] = {"This","is","a","good","day"};
    string b[] = {"This","was","good","day","hello","kitty"};
    string c[] = {"apple"};
    string d[] = {"This","is","a","bad","day","sun"};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    int n3 = sizeof(c)/sizeof(c[0]);
    int n4 = sizeof(d)/sizeof(d[0]);
    vector<string> v1(a,a+n1);
    vector<string> v2(b,b+n2);
    vector<string> v3(c,c+n3);
    vector<string> v4(d,d+n4);
    vector<vector<string> > setences;
    setences.push_back(v1);
    setences.push_back(v2);
    setences.push_back(v3);
    setences.push_back(v4);

    vector<int> result = CommonWords(setences);
    int idx1 = result[0];
    int idx2 = result[1];
    cout<<"======================"<<endl;
    Print(setences[idx1]);
    Print(setences[idx2]);
    
    return 0;
}

vector<int> CommonWords(vector<vector<string> > &setences){
    vector<int> result(2, -1);
    if(setences.size() < 2) return result; 
    sort(setences.begin(), setences.end(), compare);
    
    unordered_set<pair<int, int>, pair_hash> visited;
    queue<pair<int, int> > q;
    int max_len = 0;

    pair<int, int> cur = make_pair(0,1);
    q.push(cur);
    visited.insert(cur);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        vector<string> v1 = setences[cur.first];
        vector<string> v2 = setences[cur.second];
        cout<<cur.first<<" --- ";
        Print(v1);
        cout<<cur.second<<" --- ";
        Print(v2);
        int len = CompareWords(v1, v2);
        if(len > max_len){
            max_len = len;
            cout<<"max_len "<<max_len<<endl;
            result[0] = cur.first;
            result[1] = cur.second;
        }
        //early termination
        if(cur.second + 1 < setences.size() && len >= setences[cur.second+1].size() && len >= setences[cur.first+1].size()){
            cout<<" break "<<endl;
            break;
        }
        //push new pair
        int idx1 = cur.first + 1;
        int idx2 = cur.second;
        if(idx1 < setences.size() && idx1 > idx2){
            Swap(idx1, idx2);
        }
        if(idx1 < setences.size() && idx1 != idx2 && visited.find(make_pair(idx1,idx2))==visited.end()){
            pair<int, int> next = make_pair(idx1,idx2);
            q.push(next);
            visited.insert(next);
        }
        //push another new pair
        int idx3 = cur.first;
        int idx4 = cur.second + 1;
        if(idx4 < setences.size() && idx3 > idx4){
            Swap(idx3, idx4);
        }
        if(idx4 < setences.size() && idx3 != idx4 && visited.find(make_pair(idx3,idx4))==visited.end()){
            pair<int, int> next = make_pair(idx3,idx4);
            q.push(next);
            visited.insert(next);
        }
    }
    return result;
}

int CompareWords(vector<string> &v1, vector<string> &v2){
    int count = 0;
    unordered_set<string> s;
    
    for(int i = 0; i < v1.size(); ++i){
        if(s.find(v1[i]) == s.end()){
            s.insert(v1[i]);
        }
    }
    
    for(int i = 0; i < v2.size(); ++i){
        if(s.find(v2[i]) != s.end()){
            count++;
        }
    }
    
    return count;
}

bool compare(vector<string> &v1, vector<string> &v2){
    return v1.size() > v2.size();
}

void Swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void Print(vector<string> &v){
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

/*
best first search
sort according to the length of sentence
set to avoid duplicates
termination:
cur result is equal or longer than the length of next setence
*/
