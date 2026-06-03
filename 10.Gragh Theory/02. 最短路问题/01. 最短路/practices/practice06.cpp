//https://www.luogu.com.cn/problem/P8802
#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
typedef long long ll;

int main(){
    int n,m,s = 1;cin>>n>>m;
    vector<vector<pair<int,ll> > > g(n+1);
    vector<ll> dis(n+1,INF);
    vector<ll> val(n+1);
    for(int i = 1;i<=n;i++) cin>>val[i];
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    if(n == 1) return 0;
    dis[s] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,u] = pq.top();pq.pop();
        if(d != dis[u]) continue;
        for(auto [v,w]:g[u]){
            if(dis[v] > val[v] + dis[u] + w){
                dis[v] = val[v] + dis[u] + w;
                pq.push({dis[v],v});
            }
        }
    }
    cout<<dis[n] - val[n];
    return 0;
}