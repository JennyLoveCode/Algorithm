/*
1. Remove all ‘a’ and replace all “ ” to “20%” in a string (suppose the string 
has enough space, the extra space contains ‘*’).
*/
#include <iostream>
#include <string>
using namespace std;

string RemoveAndReplace(string , char , char , string );

int main(){
    string str = "JEaNNaY LOaVE CaODE***************************";
    char remove_c ='a';
    char replace_c =' ';
    string obj = "20%";
    string result =  RemoveAndReplace(str, remove_c, replace_c, obj);
    cout<<result<<endl;
    return 0;
}

string RemoveAndReplace(string str, char remove_c, char replace_c, string obj){
    int count = 0;
    //string size after removing
    int m = 0;
    int j = 0;
    //remove char c from string
    //count " " at the same time
    for(int i = 0; str[i] != '*';){
        if(str[i] == replace_c){
            count++;
        }
        if(str[i] != remove_c){
            str[j++] = str[i++];
        }
        else{
            i++;
        }
    }
    m = j;
    //ultimate length of new string
    int n = count*(obj.size()-1)+m;
    for(int i = m-1, j = n-1; i >=0;){
        if(str[i] == replace_c){
            for(int k = obj.size()-1; k >=0; --k){
                str[j--] = obj[k];
            }
            --i;
        }
        str[j--] = str[i--];
    }
    return str.substr(0,n);
}