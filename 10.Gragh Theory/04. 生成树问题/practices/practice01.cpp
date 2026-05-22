//https://www.luogu.com.cn/problem/P1195
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v;
    ll w;
};
struct DSU{
    vector<int> fa,sz;

    DSU(int n) : fa(n),sz(n,1){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
    }

    bool merge(int x,int y){
        x = find(x),y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};
ll ans = 0;
int cnt = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;cin>>n>>m>>k;
    if(n == k){
        cout<<0<<endl;
        return 0;
    }
    vector<Edge> e(m);
    DSU dsu(n+1);
    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    ranges::sort(e,[&](const auto&a,const auto&b){
        return a.w < b.w;
    });
    auto Kruskal = [&]() -> void {
        for(auto [u,v,w]:e){
            if(dsu.merge(u,v)){
                ans += w;
                cnt++;
                if(cnt == n - k) break;
            }
        }
    };
    Kruskal();
    if(cnt != n - k) cout<<"No Answer"<<endl;
    else cout<<ans<<endl;
    return 0;
}