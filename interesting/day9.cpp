#include<iostream>
#include<vector>
using namespace std;
int n;
int main(){
	cin>>n;
	cin.ignore();
	vector<string> arr(1010);
	string s;
	int i = 1;
	int index;
	int ch = 0;
	int num;
	while(getline(cin,s)){
		if(i<=n) arr[i++] =s;
		if(s[0]=='@'){
			int start = 0;
			int end =0 ;
			string sub;
			for(int j = 4;j<s.length();j++){
				if(s[j] == ',') start = j;
				if(s[j]==' '){
				 end = j;
				 break;
				}
			}
			sub = s.substr(start+1,end-start-1);
			num = stoi(sub);
			getline(cin,s);
			char op = s[0];
			s.erase(0,1);
			for(index =1;index<=n;index++){
				if(s!=arr[index]) cout<<arr[index]<<endl;
				else break;
			}
			if(op==' '){
				cout<<s<<endl;
				index++;
				ch++;
			}
			if(op=='-'){
				index++;
				ch++;
			}
		}
		if(s[0]==' '){
			s.erase(0,1);
			cout<<s<<endl;
			index++;
			ch++;
		}
		if(s[0]=='-'){
			index++;
			ch++;
		}
		if(s[0]=='+'){
			s.erase(0,1);
			cout<<s<<endl;
		}
		if(ch==num){
			for(int j = index;j<=n;j++){
				cout<<arr[j]<<endl;
			}
		}
	}
	return 0;
} 