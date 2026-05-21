//https://www.luogu.com.cn/problem/P3379
/*
因为这个模板题会把倍增法卡超时,所以这个题作为离线算法Tarjan算法的模板题
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;cin>>n>>m>>s;
    
    vector<vector<int> > g(n+1);
    vector<int> anstor(n+1,0);
    vector<vector<pair<int,int> > > qry(n+1);
    vector<int> ans(m+1,0);
    vector<int> fa(n+1);
    vector<bool> vis(n+1,false); 
    
    iota(fa.begin(),fa.end(),0);
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        qry[u].push_back({v,i});
        qry[v].push_back({u,i});
    }
    auto find = [&](this auto&& find,int x) -> int {
        return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
    };
    auto merge = [&](int x,int y) -> void {
        x = find(x),y = find(y);
        if(x != y) fa[y] = x;
    };
    auto tarjan = [&](this auto&& tarjan,int u,int far) -> void {
        vis[u] = true;
        anstor[find(u)] = u;
        for(auto v:g[u]){
            if(v == far) continue;
            tarjan(v,u);
            merge(u,v);
            anstor[find(u)] = u;
        }
        for(auto [v,id]:qry[u]){
            if(vis[u]){
                ans[id] = anstor[find(v)];
            }
        }
    };
    tarjan(s,0);
    for(int i = 0;i<m;i++) cout<<ans[i]<<endl;
    return 0;
}