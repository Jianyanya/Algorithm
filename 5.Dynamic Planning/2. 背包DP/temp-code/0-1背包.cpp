//https://www.luogu.com.cn/problem/P2871
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ans = 0;
int main(){
    cin>>n>>m;
    vector arr(n,vector<ll>(2,0));
    vector<ll> dp(m+1,0);
    for(int i = 0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i = 0;i<n;i++){
        //从后往前是避免二次使用dp[j],不然是多次了
        for(int j = m;j>=arr[i][0];j--){
            dp[j] = max(dp[j],dp[j-arr[i][0]] + arr[i][1]);
        }
    }
    cout<<dp[m];
    return 0;
}