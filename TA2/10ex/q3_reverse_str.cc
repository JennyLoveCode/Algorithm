/*
Use recursion to reverse a string.
*/

string Reverse(string s){
    ReverseHelp(s, 0, s.size()-1);
}

void ReverseHelp(string &s, int begin, int end){
    if(begin < end){
        swap(s[begin], s[end]);
        ReverseHelp(s, ++begin, --end);
    }
}