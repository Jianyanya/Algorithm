//https://www.luogu.com.cn/problem/P4568
/*
经典分层图最短路问题
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

int main(){
    int n,m,k;cin>>n>>m>>k;
    int s,t;cin>>s>>t;
    vector<vector<pair<int,ll> > > g((k+1)*n + 1);
    vector<ll> dis((k+1)*n + 1,INF);
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        for(int j = 1;j<=k;j++){
            g[u + j*n].push_back({v + j*n,w});
            g[v + j*n].push_back({u + j*n,w});
            g[u + (j - 1)*n].push_back({v + j*n,0});
            g[v + (j -1)*n].push_back({u + j*n,0});
        }
    }
    //这个是为了解决答案不在最后一层的这个特殊情况的简便方法
    //让每一次的终点从头开始连接到一起,这样在Dijkstra里面会把每层的答案到最后
    for(int i = 1;i<=k;i++) g[t + (i - 1)*n].push_back({t + i*n,0});
    auto Dijkstra = [&]() -> void {
        dis[s] = 0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int> > > pq;
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
    Dijkstra();
    /*
    这个是为了避免答案不在最后一层的这个特殊情况的最直观解决方法
    ll ans = LLONG_MAX;
    for(int i = 0;i<=k;i++){
        ans = min(ans,dis[t + i*n]);
    }
    */
    cout<<dis[t + k*n];
    return 0;
}