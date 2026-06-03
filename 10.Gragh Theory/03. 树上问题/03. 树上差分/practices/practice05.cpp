//https://www.luogu.com.cn/problem/P9246
#include<bits/stdc++.h>
using namespace std;
const int LOG = 31;
typedef long long ll;
const int N = 1e5 + 10;

int n,m;
vector<vector<pair<int,int> > > g(N);
vector<vector<int> > f(N,vector<int>(LOG+1));
vector<ll> dis(N,0),dep(N,0);
vector<int> tag(N,0);

void dfs(int u,int fa){
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = 1;i<=LOG;i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(auto [v,id]:g[u]){
        if(v == fa) continue;
        tag[v] = id;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = LOG;i>=0;i--){
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
    }
    if(u == v) return u;
    for(int i = LOG;i>=0;i--){
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
void add_path(int u,int v){
    int w = lca(u,v);
    dis[u]++;
    dis[v]++;
    dis[w] -= 2;
    return;
}
void dfs2(int u,int fa){
    for(auto [v,id]:g[u]){
        if(v == fa) continue;
        dfs2(v,u);
        dis[u] += dis[v];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int ans = -1;
    for(int i =1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs(1,0);
    for(int i = 1;i<=m;i++){
        int u,v;cin>>u>>v;
        add_path(u,v);
    }
    dfs2(1,0);
    for(int i = 1;i<=n;i++){
        if(dis[i] == m) ans = max(ans,tag[i]);
    }
    cout<<ans;
    return 0;
}