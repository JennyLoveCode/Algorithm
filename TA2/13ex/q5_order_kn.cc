/*
given two natural integers,print increasing order of all natural numbers with length k.
	k , n		
	2, 5		1, 2
			 	1, 3
				1, 4
*/
#include <iostream>
#include <vector>
using namespace std;

void OrderPrint(int n, int len);
void OrderPrintHelp (int n, int len, int idx, vector<int> &path);
void print (vector<int> &v);

int main(){
    int n = 5;
    int k = 2;
    OrderPrint(n, k);
    return 0;
}

void OrderPrint(int n, int len) {
    vector<int> path;
    OrderPrintHelp(n, len, 1, path);
}

void OrderPrintHelp (int n, int len, int idx, vector<int> &path) {
    if (path.size() == len) {
        print(path);
        return;
    }
    
    for (int i = idx; i < n; ++i) {
        path.push_back(i);
        OrderPrintHelp(n, len, i+1, path);
        path.pop_back();
    }
}

void print (vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
