//https://www.luogu.com.cn/problem/P1113
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n+1);
    vector<vector<int> > g(n+1);
    vector<int> in(n+1);
    vector<int> dp(n+1,0);
    for(int i = 1;i<=n;i++){
        int id;cin>>id>>arr[id];
        int v;
        while(cin>>v && v != 0){
            g[v].push_back(id);
            in[id]++;
        }
    }
    queue<int> q;
    for(int i = 1;i<=n;i++) if(in[i] == 0){ q.push(i),dp[i] = arr[i];}
    while(!q.empty()){
        auto u = q.front();q.pop();
        for(auto v:g[u]){
            in[v]--;
            dp[v] = max(dp[v],dp[u] + arr[v]);
            if(in[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) ans = max(ans,dp[i]);
    cout<<ans;
    return 0;
}