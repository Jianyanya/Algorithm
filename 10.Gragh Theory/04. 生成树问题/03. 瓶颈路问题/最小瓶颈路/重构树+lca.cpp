//https://vjudge.net/problem/LibreOJ-137
/*
重构树 + lca求法
但是这个题会超时,因为询问量太大了
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int LOG = 31;

ll A,B,C,P;
inline int rnd(){return A=1LL*(A*B+C)%P;}

struct Edge{
    int u,v;
    ll w;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) : fa(n),sz(n,1) {
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x] == x?fa[x]:fa[x] = find(fa[x]);
    }

    bool merge(int x,int y){
        x = find(x),y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};

int n,m,id;
vector<vector<int> > g;
vector<Edge> e;
vector<int> dep,val,dis;
vector<vector<int> > f;

void dfs(int u,int fa){
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = 1;i<=LOG - 1;i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(auto v:g[u]){
        if(v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = LOG - 1;i>=0;i--){
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
    }
    if(u == v) return u;
    for(int i = LOG - 1;i>=0;i--){
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;

    g.assign(2*(n+1),{});
    e.assign(m,{});
    dep.assign(2*(n+1),0),val.assign(2*(n+1),0),f.assign(2*(n+1),vector<int>(LOG)),dis.assign(2*(n+1),0);

    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end(),[&](const auto& a,const auto& b){
        return a.w < b.w;
    });
    DSU dsu(2*(n+1));
    id = n;
    for(auto [u,v,w]:e){
        u = dsu.find(u),v = dsu.find(v);
        if(u == v) continue;
        id++;
        val[id] = w;
        g[id].push_back(u);
        g[id].push_back(v);
        dsu.fa[u] = dsu.fa[v] = id;
        dsu.fa[id] = id;
    }
    dep[id] = 1;
    dfs(id,id);
    int q;cin>>q;
    cin>>A>>B>>C>>P;
    ll ans = 0;
    while(q--){
        int u = rnd()%n+1,v = rnd()%n+1;
        ans = (ans + val[lca(u,v)])%MOD;
    }
    cout<<ans;
    return 0;
}
