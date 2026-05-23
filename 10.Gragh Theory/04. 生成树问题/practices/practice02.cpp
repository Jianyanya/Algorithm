//https://www.luogu.com.cn/problem/P2504
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v;
    double w;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) : fa(n),sz(n){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;cin>>m;
    vector<int> arr(m);
    for(int i = 0;i<m;i++) cin>>arr[i];
    int n;cin>>n;
    vector<Edge> e;
    vector<pair<int,int> > dist(n+1);
    for(int i = 1;i<=n;i++) cin>>dist[i].first>>dist[i].second;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i != j){
                double w = sqrt((dist[i].first - dist[j].first)*(dist[i].first - dist[j].first) + (dist[i].second - dist[j].second)*(dist[i].second - dist[j].second));
                e.push_back({i,j,w});
            }
        }
    }
    int cnt = 0;
    double res = 0;
    DSU dsu(n+1);
    ranges::sort(e,[&](const auto&a,const auto&b){
        return a.w < b.w;
    });
    auto Kruskal = [&]() -> void {
        for(auto [u,v,w]:e){
            if(dsu.merge(u,v)){
                res = max(res,w);
                cnt++;
                if(cnt == n - 1) break;
            }
        }
    };
    Kruskal();
    int ans = 0;
    for(int i = 0;i<m;i++){
        if(arr[i] >= res) ans++;
    }
    cout<<ans;
    return 0;
}