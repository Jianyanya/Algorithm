//http://poj.org/problem?id=1679
/*
跟同权分组法差不多,只是该方法用显式的方法判断同权候选边是否成环
要使用临时并查集,实现的复杂度极高,故不常用
临时并查集合并失败
=
同权候选边成环
=
MST 不唯一
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v;
    ll w;
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
    ll ans = 0;
    bool flg = true;
    for(int l = 0;l<m;){
        int r = l;
        while(r < m && e[r].w == e[l].w) r++;
        vector<pair<int,int> > sum;
        vector<int> nodes;
        for(int i = l;i<r;i++){
            int u = dsu.find(e[i].u);
            int v = dsu.find(e[i].v);
            if(u == v) continue;
            sum.push_back({u,v});
            nodes.push_back(u);
            nodes.push_back(v);
        }
        sort(nodes.begin(),nodes.end());
        nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
        DSU tmp(nodes.size() + 1);
        for(auto p:sum){
            int x = id(p.first,nodes),y = id(p.second,nodes);
            if(!tmp.merge(x,y)) flg = false;
        }
        for(int i = l;i<r;i++){
            if(dsu.merge(e[i].u,e[i].v)){
                ans += e[i].w;
            }
        }
        l = r;
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