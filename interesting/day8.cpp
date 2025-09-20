#include<iostream>
#include<string>
#include<vector>
#include <utility>
#include <algorithm>
using namespace std;
string strs;
string check(vector<vector<char>> &id,string s){
	for(char &c:s){
		for(auto &d:id){
			if(c==d[0]){
				c = d[1];
				break;
			}
		}
	}
	return s; 
}
int main(){
	getline(cin,strs);
	int n;
	cin>>n;
    cin.ignore();
	vector<vector<char>> arr(n,vector<char>(2)); 
	for(int i = 0;i<n;i++){
		string str;
		getline(cin,str);
		arr[i][0] = str[1];
        arr[i][1] = str[2];
	}
	int m;cin>>m;cin.ignore();
	vector<string> temp(m);
	vector<pair<int,int>> index; 
	for(int i = 0;i<m;i++){
		int cnt;cin>>cnt;
		index.emplace_back(cnt,i);
	}
	sort(index.begin(),index.end());
	int p = 0;
	for(auto &d:index){
		int i = d.second;
		for(int l = p;l<d.first;l++){
			strs = check(arr,strs);
		}
		p = d.first;
		temp[i] = strs;
	}
	for(string &q:temp){
		cout<<q<<endl;
	}
	return 0;
} 