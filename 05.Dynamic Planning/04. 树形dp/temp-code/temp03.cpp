//https://www.luogu.com.cn/problem/P3478
/*
换根dp
换根dp顾名思义就是对根的状态转移
在换一个根的时候,所有的节点的权值或者状态会改变,在任意改变根节点的时候,这个变化或许是有规律的
于是本质就是利用已知条件简化计算
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<int> > g(n+1);
    vector<ll> depth(n+1,0);
    vector<ll> sz(n+1,0);
    vector<ll> dp(n+1,0);
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](this auto&& dfs,int u,int fa) -> void {
        sz[u] = 1;
        depth[u] = depth[fa] + 1;
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs(v,u);
            sz[u] += sz[v];
        }
        return ;
    };
    auto dps = [&](this auto&& dps,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dp[v] = dp[u] + n - 2*sz[v];
            dps(v,u);
        }
    };
    dfs(1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++) sum += depth[i];
    dp[1] = sum;
    dps(1,0);
    int ans = 1;
    for(int i = 2;i<=n;i++){
        if(dp[i] > sum){
            ans = i;
            sum = dp[i];
        }
    }
    cout<<ans;
    return 0;
}