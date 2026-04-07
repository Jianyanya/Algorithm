//https://www.luogu.com.cn/problem/P1616
#include<bits/stdc++.h>
using namespace std;

long long n,m;
int main(){
    cin>>m>>n;
    vector arr(n,vector<int>(2,0));
    vector<long long> dp(m+1,0);
    for(int i = 0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i = 0;i<n;i++){
        for(int j = arr[i][0];j<=m;j++){
            dp[j] = max(dp[j],dp[j-arr[i][0]] + arr[i][1]);
        }
    }
    cout<<dp[m];
    return 0;
}