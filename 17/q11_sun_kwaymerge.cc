/*
我写了个k-way merge 的code，你看看是不是说//Overload the < operator.
的地方有点和自己想的正好相反。  就是说 e1 和e2的 <号的方向 :)
*/

// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

//Define a custom data type.
class Element {
public:
    int array_index_;
    int element_index_;  // the index of the element in its array.
    int value_;
    Element(): array_index_(0), element_index_(0), value_(-1) { }
    Element(int array_index, int element_index, int value) :
        array_index_(array_index),
        element_index_(element_index),
        value_(value) { }
};

//Overload the < operator.
bool operator< (const Element &e1, const Element &e2)
{
    return e1.value_ > e2.value_;
}

vector<int> KWayMerge(vector<vector<int> >& vv) {
    vector<int> solu;
    //Declare a priority_queue and specify the ORDER as <
    //The priorities will be assigned in the Ascending Order of Age
    priority_queue<Element, vector<Element>,less<vector<Element>::value_type> > pq_less;

   // Add container elements.
    for (int i = 0; i < vv.size(); i++) {
        pq_less.push( Element(i, 0, vv[i][0]) );
    }

    while (!pq_less.empty()) {
        Element top_e = pq_less.top();
        pq_less.pop();
        solu.push_back(top_e.value_);
        if (top_e.element_index_ < vv[top_e.array_index_].size() - 1) {
            pq_less.push(
                Element(top_e.array_index_,
                        top_e.element_index_ + 1,
                        vv[top_e.array_index_][top_e.element_index_ + 1]));
        }
    }
    return solu;
}

int main(){
    vector<int> a1, a2, a3;
    for (int i = 0; i < 5; i++) {
        a1.push_back(3*i);
        a2.push_back(3*i + 1);
        a3.push_back(3*i + 2);
    }
    vector<vector<int> > vv;
    vv.push_back(a1);
    vv.push_back(a2);
    vv.push_back(a3);
    vector<int> result = KWayMerge(vv);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "-";
    }
    cout <<endl;

    return 0;
}