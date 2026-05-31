#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int n;
int main(){
	cin>>n;
	while(n--){
		string str;cin>>str;
		unordered_map<char,int> mp;
		bool word = false,num = false,chars = false,h = true; 
		for(char c:str){
			mp[c]++;
			if(mp[c]>2) h = false;
			if(c>='a'&&c<='z'||c>='A'&&c<='Z') word = true;
			if(c>='0'&&c<='9') num = true;
			if(c == '*' || c == '#') chars = true;
		}
		if(word&&num&&chars&&h) cout<<2;
		else if(word&&num&&chars) cout<<1;
		else cout<<0;
		cout<<endl;
	}
	return 0;
} 
