#include<iostream>
#include<vector>
using namespace std;
int n,k;
int dfs(vector<int>& arr,int i,int s){
	if(i==0) return s;
	int res = 0;
	for(int x = 1;x<=k;x++){
		res = max(res,dfs(arr,i-x,s+arr[x-1]));
	}
	return res;
}
int main(){
	cin>>n>>k;
	vector<int> arr(k);
	for(int i = 0;i<k;i++){
		cin>>arr[i];
	}
	cout<<dfs(arr,n,0);
	return 0;
} 