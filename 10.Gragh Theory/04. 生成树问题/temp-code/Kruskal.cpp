//https://www.luogu.com.cn/problem/P3366
/*
对边权进行排序,从小的边开始选,最后成一个数量大小为n的集合
利用并查集判断选的边的端点是否在集合内,如果都已经在一个集合内了(成环了),就跳过
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
    int n,m;cin>>n>>m;
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
                if(cnt == n - 1) break;
            }
        }
    };
    Kruskal();
    if(cnt != n-1) cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}