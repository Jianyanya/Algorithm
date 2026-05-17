//https://www.luogu.com.cn/problem/P5905
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

struct Edge{
    int u,v;
    ll w;
};

int main(){
    int n,m;cin>>n>>m;
    vector<Edge> e;
    vector<ll> h(n+1,INF);
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    auto Bellman_Ford = [&]() -> bool {
        h[0] = 0;
        bool flg = false;
        vector<Edge> all = e;
        for(int i = 1;i<=n;i++) all.push_back({0,i,0});
        for(int i = 1;i<=n;i++){
            flg = false;
            for(auto [u,v,w]:all){
                if(h[u] == INF) continue;
                if(h[v] > h[u] + w){
                    h[v] = h[u] + w;
                    flg = true;
                }
            }
            if(!flg) break;
        }
        return flg;
    };
    if(Bellman_Ford()){
        cout<<-1;
        return 0;
    }
    vector<vector<pair<int,ll> > > g(n+1);
    for(auto [u,v,w]:e){
        ll nw = h[u] + w - h[v];
        g[u].emplace_back(v,nw);
    }
    vector<ll> dis(n+1,INF);
    auto Dijkstra = [&](int s) -> void {
        dis.assign(n+1,INF);
        priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
        dis[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            auto [d,u] = pq.top();pq.pop();
            if(d != dis[u]) continue;
            for(auto [v,w]:g[u]){
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
    };
    for(int s = 1;s<=n;s++){
        Dijkstra(s);
        ll ans = 0;
        for(int t = 1;t<=n;t++){
            ll sum = t;
            if(dis[t] == INF) sum *= 1e9;
            else if(s != t) sum *= dis[t] - h[s] + h[t];
            else if(s == t) sum = 0;
            ans += sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}