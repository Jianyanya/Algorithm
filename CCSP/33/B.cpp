#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int a,b;
string lr(string s){
	for(char &c:s){
		c = tolower(c);
	}
	return s;
} 
int main(){
	cin>>a>>b;
	unordered_map<string,int> mp;
	int A = a;
	while(a--){
		string str;cin>>str; 
		str = lr(str);
		mp[str] = 1;
	}
	int t = 0;
	int cnt = 0;
	while(b--){
		string str;cin>>str;
		str = lr(str);
		if(mp[str]){
            t++;
            mp[str]--;
        }
		else  cnt++;
	}
	cout<<t<<endl;
	cout<<mp.size();
	return 0;
}
