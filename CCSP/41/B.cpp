#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    double ans = 0;
    //true为普通型
    vector<bool> vis(n);
    vector<int> a(n);
    vector<double> b(n);    
    vector<double> dp(m+1,0);
    for(int i = 0;i<n;i++){
        int o,t;cin>>o>>t>>a[i]>>b[i];
        if(o) vis[i] = true;
        else vis[i] = false;
        ans += t;
    }
    for(int i = 0;i<n;i++){
        if(vis[i]){
            for(int j = m;j>=a[i];j--){
                dp[j] = max(dp[j],dp[j - a[i]] + b[i]);
            }
        }else{
            for(int w = m;w>=1;w--){
                for(int k = 1;k<=a[i] && k<=w;k++){
                    dp[w] = max(dp[w],dp[w - k] + k*(1.0*b[i]/a[i]));
                }
            }
        }
    }
    ans -= dp[m];
    printf("%0.6lf",ans);
    return 0;
}