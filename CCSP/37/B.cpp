#include<iostream>
#include<vector>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	vector<int> arr(k);
	for(int i = 0;i<k;i++){
		cin>>arr[i];
	}
	vector<int> dp(n+1,0);
	for(int i = 1;i<=n;i++){
		for(int x = 1;x<=min(i,k);x++){
			dp[i] = max(dp[i],dp[i-x]+arr[x-1]);
		}
	} 
	cout<<dp[n];
	return 0;
} 
