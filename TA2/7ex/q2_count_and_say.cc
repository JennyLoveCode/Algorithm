/*
1
11
21
1211
111221
*/

string CountAndSay('1', 1, 10)

string CountAndSay(string &str, int cur, int n){
    string result = str;
    if(cur == n) return result;
    result = "";
    int count = 1;
    for(int i = 1; i < str.size(); i++){
        if(str[i] == str[i-1]){
            count++;
        }
        else{
            result += string(count)+
        }
    }
    CountAndSay(str, cur+1, n);
}