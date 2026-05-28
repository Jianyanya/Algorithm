#include<bits/stdc++.h>
using namespace std;
const int LOG = 31;

int n,m;
vector<int> val;
vector<vector<int> > g;
vector<int> f;
vector<int> dep;

void dfs(int u,int fa){
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    for(auto v:g[u]){
        if(v == fa) continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    vector<bool> vis(n + 1, false);
    while (dep[u] > dep[v]) {
        vis[val[u]] = true;
        u = f[u];
    }
    while (dep[v] > dep[u]) {
        vis[val[v]] = true;
        v = f[v];
    }
    while (u != v) {
        vis[val[u]] = true;
        vis[val[v]] = true;
        u = f[u];
        v = f[v];
    }
    vis[val[u]] = true;
    int mex = 0;
    while (vis[mex]) mex++;
    return mex;
}

int main(){
    cin>>n>>m;
    val.assign(n+1,0);
    g.assign(n+1,{});
    f.assign(n+1,0);
    iota(f.begin(),f.end(),0);
    dep.assign(n+1,0);
    for(int i = 1;i<=n;i++) cin>>val[i];
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}
