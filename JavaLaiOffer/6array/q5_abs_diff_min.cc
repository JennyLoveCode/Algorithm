/*
3 arrays A, B, C, from each of the arrays pick one element, x from A, y from B, 
z from C, what is the minimum |x-y|+ |y-z| + |z-x|.
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int Diff(vector<int>, vector<int> , vector<int>);
void DiffHelp(vector<int> v1, int i, vector<int> v2, int j, int value, int &res);
int Min(int, int, int);

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> A(a, a+n);
    
    int b[] = {3,5};
    int m = sizeof(b)/sizeof(b[0]);
    vector<int> B(b, b+m);
    
    int c[] = {0,1,2,3,5};
    int k = sizeof(c)/sizeof(c[0]);
    vector<int> C(c, c+k);
    
    int result = Diff(A,B,C);
    cout<<result<<endl;
    return 0;
}

int Diff(vector<int> A, vector<int> B, vector<int> C){
    int i = 0;
    int j = 0;
    int k = 0;
    int res = INT_MAX;
    int cur;
    
    while(true){
        cur = abs(A[i]-B[j])+abs(B[j]-C[k])+abs(C[k]-A[i]);
        cout<<"ABC cur "<<cur<<endl;
        res = min(cur, res);
        int value = Min(A[i], B[j], C[k]);
        if(value == A[i]){
            if(i == A.size()-1){
                DiffHelp(B, j, C, k, A[i], res);
                break;
            }
            ++i;
        }
        else if(value == B[j]){
            if(j == B.size()-1){
                DiffHelp(A, i, C, k, B[j], res);
                break;
            };
            ++j;
        }
        else if(value == C[k]){
            if(k == C.size()-1){
                DiffHelp(A, i, B, j, C[k], res);
                break;
            }
            ++k;
        }
    }

    return res;
}

void DiffHelp(vector<int> v1, int i, vector<int> v2, int j, int value, int &res){
    int m = v1.size();
    int n = v2.size();
    int cur;

    while(i < m && j < n){
        cur = abs(v1[i]-v2[j])+abs(v1[i]-value)+abs(v2[j]-value);
        cout<<"two cur "<<cur<<endl;
        res = min(cur, res);
        if(v1[i] < v2[j]){
            ++i;
        }
        else{
            ++j;
        }
    }
    
    while(i < m){
        cur = abs(v1[i]-v2[n-1])+abs(v1[i]-value)+abs(v2[n-1]-value);
        cout<<"one cur "<<cur<<endl;
        res = min(cur, res);
        ++i;
    }
    
    while(j < n){
        cur = abs(v1[m-1]-v2[j])+abs(v1[m-1]-value)+abs(v2[j]-value);
        cout<<"one cur "<<cur<<endl;
        res = min(cur, res);
        ++j;
    }
}

int Min(int a, int b, int c){
    int t = min(a,b);
    return min(t, c);
}
/*
sort
diff is minimum when merge arrays.
*/