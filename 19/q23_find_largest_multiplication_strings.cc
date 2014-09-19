/*
Q23, 一个字典有给一系列strings，要求找两个string,使得它们没有共同字符，并且长度乘积最大. 
(Assumption: all letters in the word is from ‘az’ in ASCII)
Example:
w1 abcde size = 5
w2 adzz size = 4
w3 abd size = 3
w4 fgz size = 3;
solution: abcde x fgz = 5 x 3 == 15
*/
#include <iostream>
#include <bitset>
#include <queue>         //priority_queue
#include <string>
#include <utility>      // std::pair
#include <vector>
using namespace std;

struct state{
    int i, j;
    string a, b;
    
    state(){ }
    state(int i_, int j_, string s1, string s2):
            i(i_),
            j(j_),
            a(s1),
            b(s2){ }
    
    bool operator < (const state &other) const{
        return a.size()*b.size() < other.a.size()*other.b.size();
    }
    
    void SwapPair(){
        swap(i, j);
        swap(a, b);
    }
};

pair<string, string> FindPair(vector<string> &);
bool CheckNoCommonLetter(string &, string &);
bool cmp(string &, string &);

int main(){
    string w1 = "abcde";
    string w2 = "adzf";
    string w3 = "abd";
    string w4 = "fgz";
    vector<string> words;
    words.push_back(w1);
    words.push_back(w2);
    words.push_back(w3);
    words.push_back(w4);

    pair<string, string> result = FindPair(words);
    cout<<result.first<<endl;
    cout<<result.second<<endl;
    cout<<"Max Multiplication is "<<result.first.size()*result.second.size()<<endl;
    return 0;
}

pair<string, string> FindPair(vector<string> &words){
    if(words.size() < 2) return make_pair("", "");
    sort(words.begin(), words.end(), cmp);
    priority_queue<state, vector<state>, less<state> > q;
    q.push(state(0,1,words[0],words[1]));
    vector<vector<bool> > visited(words.size(), vector<bool>(words.size(), false));

    while(!q.empty()){
        state cur = q.top();
        q.pop();
        
        if(CheckNoCommonLetter(cur.a,cur.b)){
            return make_pair(cur.a, cur.b);
        }
        
        if(cur.i+1< words.size()){
            state s = state(cur.i+1, cur.j, words[cur.i+1], words[cur.j]);
            if(visited[cur.i+1][cur.j] == false){
                if(cur.i > cur.j){
                    cur.SwapPair();
                }
                visited[cur.i+1][cur.j] = true;
                q.push(s);
            }
        }
        
        if(cur.j+1 < words.size()){
            state s = state(cur.i, cur.j+1, words[cur.i], words[cur.j+1]);
            if(visited[cur.i][cur.j+1] == false){
                if(cur.i > cur.j){
                    cur.SwapPair();
                }
                visited[cur.i][cur.j+1] = true;
                q.push(s);
            }
        }
    }
    return make_pair("", "");
} 

bool CheckNoCommonLetter(string &str1, string &str2){
    bitset<26> b1;
    bitset<26> b2;
    
    for(int i = 0; i < str1.size(); i++){
        b1.set(str1[i]-'a', 1);
    }

    for(int i = 0; i < str2.size(); i++){
        b2.set(str2[i]-'a', 1);
    }
    
    return (b1.to_ulong() & b2.to_ulong()) == 0;
}

bool cmp(string &a, string &b){
    return a.size() > b.size();
}