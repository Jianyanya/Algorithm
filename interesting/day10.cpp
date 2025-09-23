#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
const int MOD = 1000000007;
int n;
int main(){
	cin>>n;
	cin.ignore();
	unordered_map<string,int> mp;
	unordered_map<string,string> temp;
	string s;
	while(n--){
		getline(cin,s);
		s += " "; 
		char index = s[0];
		int num = 0;
		int pos = 1;
		string str;
		if(index=='1'){
			string t;
			bool flage = true;
			for(int i = 2;i<s.size();i++){
				if(s[i]==' '){
					if(flage) str = s.substr(pos+1,i-pos-1),flage = false;
					else{
						if(s[pos+1]=='$') t = s.substr(pos+2,i-pos-2),num= (num+mp[t])%MOD;
						else num+= i-pos-1;
					}
					pos = i;
				}
			}
			mp[str] = num%MOD;
		}
		if(index=='2'){
			int i;
			for(i = 2;i<s.size();i++){
				if(s[i]==' '){
					str = s.substr(pos+1,i-pos-1);
					break;
				}
			}
			temp[str] = s.substr(i,s.size()-i);
		}
		if(index=='3'){
			int i;
			for(i = 2;i<s.size();i++){
				if(s[i]==' '){
					str = s.substr(pos+1,i-pos-1);
					break;
				}
			}
			if(mp[str]) cout<<mp[str]%MOD<<endl;
			else{
				string tp = temp[str];
				string t;
				int posl = 0;
				int num = 0;
				for(int j = 2;j<tp.size();j++){
					if(tp[j]==' '){
						if(tp[posl+1]=='$') t = tp.substr(posl+2,j-posl-2),num= (num+mp[t])%MOD;
						else num+= j-posl-1;
                        posl = j;
                    }
				}
				cout<<num%MOD<<endl;
			}
		}
	}
	return 0;
}