/*
Q13 (binary) Given a number x, how to get the hexadecimal representation 
of the number in string type? E.g 29 ⇒ “0x1D
10 进制 ＝>0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
16 进制 => 0 1 2 3 4 5 6 7 8 9 A B C D E
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//two methods
string hexadecimal(int);
string decToHex(int);

int main(){
    int num = 29;
    //string result = hexadecimal(num);
    string result = decToHex(num);
    cout<<result<<endl;
    return 0;
}

string hexadecimal(int num){
    const string hex = "0123456789ABCDE";
    vector<char> solution;

    solution.push_back('0');
    solution.push_back('x');

    while(num/16 >= 1){
        char c = hex[num / 16];
        solution.push_back(c);
        int count = num / 16;
        num -= 16*count ;
    }
    
    char c = hex[num];
    solution.push_back(c);
    
    string result(solution.begin(), solution.end());
    return result;
}

string decToHex(int num){
    string result;
    if(num == 0){
        return "0x0";
    }
    
    const char symbols[] = "0123456789ABCDE";
    while(num > 0){
        result = symbols[num % 16] + result;
        num /= 16;
    }
    return "0x"+result;
}











