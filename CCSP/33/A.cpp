#include<iostream>
#include<vector>
using namespace std;
int n,m; 
int main(){
	cin>>n>>m;
	vector<int> cnt(m+1);
	vector<int> arr(m+1);
	for(int i = 0;i<n;i++){
		int len;cin>>len;
		vector<int> temp(m+1,0); 
		while(len--){
			int p;cin>>p;
			cnt[p]++;
			temp[p]++;
		}
		for(int j = 1;j<=m;j++){
			if(temp[j]) arr[j]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<arr[i]<<" "<<cnt[i]<<endl;
	}
	return 0;
}
