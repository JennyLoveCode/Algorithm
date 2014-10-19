/*Jian Zhang*/

/*
Question 1) Given a string, write a routine that converts the string to a long, 
without using the built in functions that would do this. Describe what (if any) 
limitations the code has. For example:

long stringToLong(String s)
{
//code goes here to convert a string to a long
}
void test()
{
long i = stringToLong("123");
if (i == 123)
// success
else
// failure
}
*/

#include <iostream>
#include <string>
using namespace std;

long StringToLong(string s) {
    long num = 0;
    int sign = 1;
    const int n = s.size();
    int i = 0;
    
    //discard white spaces
    while(s[i] == ' ' && i < n) {
        ++i;
    }

    //check sign '+' or '-'
    if(s[i] == '+') {
        ++i;
    } else if(s[i] == '-') {
        sign = -1;
        ++i;
    }

    for(; i < n; ++i){
        //avoid special characters e.g : 'a' 'f' '@' '*' '$' '%'
        if(s[i] < '0' || s[i] > '9')
            break;
        //avoid overflow
        if(num > LONG_MAX/10 || (num == LONG_MAX/10 && (s[i]-'0') > LONG_MAX%10)) {
            return sign == -1 ? LONG_MIN : LONG_MAX;       
        }
        num = num*10+s[i]-'0';
    }

    return num*sign;
}

void test_StringToLong(){
    string s1 = "123";
    long res1 = StringToLong(s1);
    if(res1 == 123){
        cout<<"Success to convert string "<<s1<<" to "<<res1<<endl;
    } else{
        cout<<"Fail to convert string "<<s1<<endl;
    }
    
    string s2 = "    678";
    long res2 = StringToLong(s2);
    if(res2 == 678){
        cout<<"Success to convert string "<<s2<<" to "<<res2<<endl;
    } else{
        cout<<"Fail to convert string "<<s2<<endl;
    }   
    
    string s3 = "+123";
    long res3 = StringToLong(s3);
    if(res3 == 123){
        cout<<"Success to convert string "<<s3<<" to "<<res3<<endl;
    } else{
        cout<<"Fail to convert string "<<s3<<endl;
    }   
    
    string s4 = "-123";
    long res4 = StringToLong(s4);
    if(res4 == -123){
        cout<<"Success to convert string "<<s4<<" to "<<res4<<endl;
    } else{
        cout<<"Fail to convert string "<<s4<<endl;
    }
    
    //two signs is not allowed
    string s5 = "-+123";
    long res5 = StringToLong(s5);
    if(res5 == 0){
        cout<<"Success to convert string "<<s5<<" to "<<res5<<endl;
    } else{
        cout<<"Fail to convert string "<<s5<<endl;
    }     

    string s6 = "123456WYZ123";
    long res6 = StringToLong(s6);
    if(res6 == 123456){
        cout<<"Success to convert string "<<s6<<" to "<<res6<<endl;
    } else{
        cout<<"Fail to convert string "<<s6<<endl;
    } 

    string s7 = "9223372036854775810";
    long res7 = StringToLong(s7);
    if(res7 == LONG_MAX){
        cout<<"Success to convert string "<<s7<<" to LONG_MAX"<<endl;
    } else{
        cout<<"Fail to convert string "<<s7<<endl;
    }

    string s8 = "-9223372036854775810";
    long res8 = StringToLong(s8);
    if(res8 == LONG_MIN){
        cout<<"Success to convert string "<<s8<<" to LONG_MIN"<<endl;
    } else{
        cout<<"Fail to convert string "<<s8<<endl;
    } 
}

int main(){
    test_StringToLong();
    return 0;
}