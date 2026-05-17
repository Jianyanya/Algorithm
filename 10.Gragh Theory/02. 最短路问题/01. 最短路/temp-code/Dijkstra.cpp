//https://www.luogu.com.cn/problem/P4779
#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
typedef long long ll;

int main(){
    int n,m,s;cin>>n>>m>>s;
    vector<vector<pair<int,ll> > > g(n+1);
    vector<ll> dis(n+1,INF);
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    dis[s] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
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
    for(int i = 1;i<=n;i++){
        if(dis[i] == INF) cout<<2147483647LL;
        else cout<<dis[i];
        cout<<" ";
    }
    return 0;
}