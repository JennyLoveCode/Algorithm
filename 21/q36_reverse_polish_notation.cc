/*
Q36. how to evaluate a Reverse Polish notation (逆波兰表达式)
Reverse Polish notation is a postfix mathematical notation where the operands
of any particular operator immediately precede the operator.
* For example, 3 + 4 would be written 3 4 + and 2 * (4 + 1) would be written 
as 4 1 + 2 * or 2 4 1
+ *
*
* Takes a list of strings representing either operators or operands and returns
* the result of a reversepolish
notation calculation on them
* Sample output:
* {"4", "1", "+", "2", "*"} >
10 ((4 + 1) * 2)
* {"5", "8", "4", "/", "+"} >
7 (5 + (8 / 4))
* Supported operators are +, ,
*, and /
* @param ops the series of operators and operands to operate on
* @return a Double equal to the result of the calculation
Reverse Polish notation advantage: we can calculate the final result without worrying 
about the precedence of the operator. 3 + 35 + ( )….
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int Convert(vector<string> str);
bool IsOperator (string c);

int main () {
    string arr[] = {"5","10","+","2","*"};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<string> str(arr, arr+n);
    int res = Convert(str);
    cout<<res<<endl;
    return 0;
}

int Convert(vector<string> str){
    stack<int> s;
    for (int i = 0; i < str.size(); ++i) {
        if (IsOperator(str[i])) {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            if (str[i].compare("+") == 0) {
                x += y;
            } else if (str[i].compare("-") == 0) {
                x -= y;
            } else if (str[i].compare("*") == 0) {
                x *= y;
            } else if (str[i].compare("/") == 0){
                x /= y;
            }
            s.push(x);
            
        } else {
            s.push(stoi(str[i]));
        }
    }
    return s.top();
}

bool IsOperator (string s) {
    return s.compare("+")*s.compare("-")*s.compare("*")*s.compare("/") == 0;
}