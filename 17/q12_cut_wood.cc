/*
Q12: (DP) 有一个长为L米的木料需要割开，可以切的位置在一个数组里A[0...N]，从一个地方切
开的cost是当前所切木料的长度。按不同的顺序切割，得到的total cost是不一样的，问怎么切
cost最小。 比如一个木料现在10米长，然后切的位置是2米处，4米处和7米处
（就是说arr A里A[0]是2，A[1]是4， A[2]是7）。那么比如先切2米，那么得到cost是
10（因为现在木料长度为10），然后切4米处，那么cost变成10 + 8(因为8是现在切的
时候木料的长度)。然后切7米处，cost变成10 + 8 + 6。那么这种切法总共的cost是24。
*/
#include <iostream>
#include <vector>
using namespace std;

int min_cost(int, vector<int> &);

int main(){
    int L = 10;
    int arr[] = {2,4,7};
    vector<int> A(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int result = min_cost(L, A);
    cout<<result<<endl;
    return 0;
}

int min_cost(int L, vector<int> &A){
    A.insert(A.begin(), 0);
    A.push_back(10);
    int n = A.size();
    vector< vector<int> > matrix(n, vector<int>(n, 0));
    for(int i = n-1; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            int min_value = INT_MAX;
            for(int k = i+1; k < j; k++){
                int cost = A[j]-A[i]+matrix[i][k]+matrix[k][j];
                min_value = min(cost, min_value);
            }
            matrix[i][j] = min_value;
        }
    }
    return matrix[0][n-1];
}