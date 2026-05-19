//https://www.luogu.com.cn/problem/P1993
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
    vector<Edge> g;
    while(m--){
        int p;cin>>p;
        if(p == 3){
            int u,v;cin>>u>>v;
            g.push_back({u,v,0});
            g.push_back({v,u,0});
        }else{
            int u,v;
            ll w;cin>>u>>v>>w;
            if(p == 1) g.push_back({u,v,-w});
            else g.push_back({v,u,w});
        }
    }
    vector<ll> dis(n+1,INF);
    for(int i = 1;i<=n;i++) g.push_back({0,i,0});
    auto Bellman_Ford = [&]() -> bool {
        dis[0] = 0;
        bool flg = false;
        for(int i = 1;i<=n;i++){
            flg = false;
            for(auto [u,v,w]:g){
                if(dis[u] == INF) continue;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    flg = true;
                }
            }
            if(!flg) break;
        }
        return flg;
    };
    if(Bellman_Ford()) cout<<"No";
    else cout<<"Yes";
    return 0;
}