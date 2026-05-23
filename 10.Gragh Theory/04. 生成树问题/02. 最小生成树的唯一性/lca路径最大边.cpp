//http://poj.org/problem?id=1679
/*
这个方法常用于次小生成树
先求一棵 MST
枚举每条非树边 (u,v,w)
如果 MST 上 u-v 路径最大边 == w
则可以等权替换，MST 不唯一
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v;
    ll w;
    bool in;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) :fa(n),sz(n,1){
        iota(fa.begin(),fa.end(),0);
    }
    
    int find(int x) { return fa[x] == x?x:fa[x] = find(fa[x]); }

    bool merge(int from,int to){
        int x = find(from),y = find(to);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int n,m;
int id(int x,vector<int> arr){
    return int(lower_bound(arr.begin(),arr.end(),x)-arr.begin())+1;
}
void solve(){
    cin>>n>>m;
    vector<Edge> e(m);
    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end(),[&](const auto&a,const auto&b){
        return a.w < b.w;
    });
    DSU dsu(n+1);
    vector<vector<pair<int,ll> > > tree(n+1);
    ll ans = 0;
    int cnt = 0;
    for(auto &ed:e){
        if(dsu.merge(ed.u,ed.v)){
            ed.in = true;
            cnt++;
            ans += ed.w;
            tree[ed.u].push_back({ed.v,ed.w});
            tree[ed.v].push_back({ed.u,ed.w});
        }
    }
    if(cnt < n-1){
        cout<<"No MST\n";
        return;
    }

    int LOG = 1;
    while((1<<LOG) <= n) LOG++;

    vector<int> dep(n+1,0);
    vector<vector<int> > fa(LOG,vector<int>(n+1,0));
    vector<vector<ll> > mx(LOG,vector<ll>(n+1,LLONG_MIN));

    function<void(int,int)> dfs=[&](int u,int father){
        fa[0][u] = father;
        for(int k=1;k<LOG;k++){
            fa[k][u] = fa[k-1][fa[k-1][u]];
            mx[k][u] = max(mx[k-1][u],mx[k-1][fa[k-1][u]]);
        }
        for(auto [v,w]:tree[u]){
            if(v == father) continue;
            dep[v] = dep[u]+1;
            mx[0][v] = w;
            dfs(v,u);
        }
    };

    dfs(1,0);

    function<int(int,int)> queryMax = [&](int u,int v){
        ll res = LLONG_MIN;
        if(dep[u] < dep[v]) swap(u,v);
        int diff = dep[u] - dep[v];
        for(int k=LOG-1;k>=0;k--){
            if(diff>>k&1){
                res = max(res,mx[k][u]);
                u = fa[k][u];
            }
        }
        if(u == v) return res;
        for(int k=LOG-1;k>=0;k--){
            if(fa[k][u] != fa[k][v]){
                res = max({res,mx[k][v],mx[k][u]});
                u = fa[k][u];
                v = fa[k][v];
            }
        }
        res = max({res,mx[0][v],mx[0][u]});
        return res;
    };

    bool flg = true;

    for(auto ed:e){
        if(ed.in) continue;
        ll mxEdge = queryMax(ed.u,ed.v);
        if(mxEdge == ed.w){
            flg = false;
            break;
        }
    }
    if(flg) cout<<ans<<endl;
    else cout<<"Not Unique!"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}