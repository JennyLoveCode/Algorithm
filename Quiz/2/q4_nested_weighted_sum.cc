/*
Q4：Nested integer weighted sum. 一个list, 元素可能是list，也可能是Integer，但是每个元素都
包装在NestedInteger类里面了，求weighted sum. 例子是{2{4{6}}}. 应该返回2×1 + 4×2 + 6×3.
upgrade: {-21{4{6}}}
*/
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

void WeightedSum(string str, int &, int , int);

int main(){
    string str = "{21{-42{6}}}";
    int sum = 0;
    WeightedSum(str,sum,0,0);
    cout<<sum<<endl;
    return 0;
}

void WeightedSum(string str, int &sum, int level, int idx){
    if(str[idx] == '}'){
        return;
    }
    bool negative = false;
    int val = 0;
    int i = idx;
    //parse number in this level
    for(; i < str.size(); ++i){
        if(str[i] == '-'){
            negative = true;
            continue;
        }
        if(isdigit(str[i])){
            val = val*10+(str[i]-'0');
        }
        else{
            break;
        }
    }
    //update sum
    if(negative){
        sum -= val*level;
    }
    else{
        sum += val*level;
    }
    if(str[i] == '{') WeightedSum(str, sum, level+1, i+1);
}