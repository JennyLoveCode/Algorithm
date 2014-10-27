/*
insert interval
merge interval
*/
#include <iostream>
#include <vector>
using namespace std;

struct Interval{
    int begin;
    int end;
    Interval () {}
    ~Interval () {}
    Interval (int b, int e) : begin(b), end(e) {}
};

void Insert (vector<Interval> &v, Interval inter);
vector<Interval> Merge (vector<Interval> v);
void print (vector<Interval> &v);

int main () {
    Interval i1(1,3);
    Interval i2(2,5); 
    Interval i3(6,9);

    vector<Interval> v;
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);

    Interval inter(1,10);
    //Insert(v, inter);
    
    vector<Interval> res = Merge(v);
    print(res);
    return 0;
}

void Insert (vector<Interval> &v, Interval inter) {
    //extreme cases
    if (v.empty()) {
        v.push_back(inter);
        return;
    }
    //early termination
    if(inter.begin <= v[0].begin && inter.end >= v[v.size()-1].end){
        v.clear();
        v.push_back(inter);
        return;
    }
    vector<Interval> :: iterator it = v.begin();
    while (it != v.end()) {
        if (inter.end < it->begin) {
            v.insert(it, inter);
            return;
        } else if (inter.begin > it->end) {
            ++it;
        } else { //overlapping
            inter.begin = min(inter.begin, it->begin);
            inter.end = max(inter.end, it->end);
            it = v.erase(it);
        }
    }
    v.push_back(inter);
    return;
}

vector<Interval> Merge (vector<Interval> v) {
    if (v.size() < 2) {
        return v;
    }
    vector<Interval> res;
    for (int i = 0;  i < v.size(); ++i) {
        Insert(res, v[i]);
    }
    return res;
}

void print (vector<Interval> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<"("<<v[i].begin<<","<<v[i].end<<")  ";
    }
    cout<<endl;
}