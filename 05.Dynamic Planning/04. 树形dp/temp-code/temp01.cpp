//https://www.luogu.com.cn/problem/P1352
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int> > dp(n+1,vector<int>(2,0));
    vector<vector<int> > g(n+1);
    vector<bool> arr(n+1,false);
    vector<bool> vis(n+1,false);
    for(int i = 1;i<=n;i++) cin>>dp[i][1];
    for(int i = 1;i<=n;i++){
        int l,k;cin>>l>>k;
        arr[l] = true;
        g[k].push_back(l);
    }
    auto dfs = [&](this auto&& dfs,int u) -> void {
        for(auto v:g[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            dfs(v);
            dp[u][0] += max(dp[v][0],dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    for(int i = 1;i<=n;i++){
        if(!arr[i]){
            dfs(i);
            cout<<max(dp[i][0],dp[i][1]);
        }
    }
    return 0;
}