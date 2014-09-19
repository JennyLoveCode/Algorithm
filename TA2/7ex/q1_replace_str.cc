/*
1. Remove all ‘a’ and replace all “ ” to “20%” in a string (suppose the string 
has enough space, the extra space contains ‘*’).
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    
}

string RemoveAndReplace(string str, char a, string obj){
    int i = 0;
    int j = 0;
    int count = 0;
    while(str[i] != '*'){
        if(str[i] != a){
            str[j++] = str[i++];
        }
        else{
            i++;
        }
    }
    int size = j;
}