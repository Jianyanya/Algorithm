//https://vjudge.net/problem/LibreOJ-137
/*
这里是重构树 + 欧拉序列RMQ
因为题目数据实在太大了,不好预处理内存,所以直接动态扩容(assign)
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
vector<ll> val;
vector<int> euler,first,dep,lg;
vector<vector<int> > st;

void dfs(int u){
    first[u] = euler.size();
    euler.push_back(u);
    for(auto v:g[u]){
        dep[v] = dep[u] + 1;
        dfs(v);
        euler.push_back(u);
    }
}

int better(int x,int y){
    return dep[x] < dep[y]?x:y;
}

void rmq(){
    int len = euler.size();
    lg.assign(len + 1,0);
    for(int i = 2;i<=len;i++) lg[i] = lg[i/2] + 1;

    int K = lg[len] + 1;
    st.assign(K,vector<int>(len));
    for(int i = 0;i<len;i++) st[0][i] = euler[i];

    for(int k = 1;k<K;k++){
        for(int i = 0;i + (1<<k)<=len;i++){
            st[k][i] = better(st[k - 1][i],st[k - 1][i + (1<<(k - 1))]);
        }
    }
}

int lca(int u,int v){
    int l = first[u],r = first[v];
    if(l > r) swap(l,r);
    int k = lg[r - l + 1];
    return better(st[k][l],st[k][r - (1<<k) + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;

    g.assign(2*(n+1),{});
    e.assign(m,{});
    val.assign(2*(n+1),0);
    first.assign(2*(n+1),-1);
    dep.assign(2*(n+1),0);

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
    dfs(id);
    rmq();
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
