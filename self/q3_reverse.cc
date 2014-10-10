/*
*/

reverse a string 
string Reverse(string &s){
	int begin = 0;
	int end = s.size()-1;
	while(begin < end){
		swap(s[begin++], s[end--]);
}
return s;
}

“I am good” -> “good am I”
	string ReverseSentence(string &s){
		//reverse each words in the sentence
		for(int i = 0; i < s.size();){
	//get ending index of the word
int j =i;
	while(s[j] != ‘ ’){
	j++;
	if(j == s.size()){
	break;
}
}
Reverse(s, i, j-1 );
//update beginning index
i = j+1;
}
//reverse whole string
Reverse(s, 0, s.size()-1);
return s;
}