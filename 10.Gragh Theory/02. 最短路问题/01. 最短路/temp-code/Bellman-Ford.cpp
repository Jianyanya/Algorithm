//https://www.luogu.com.cn/problem/P3371
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

struct Edge{
    int u,v;
    ll w;
};

int main(){
    int n,m,s;cin>>n>>m>>s;
    vector<Edge> e(m);
    vector<ll> dis(n+1,INF);
    dis[s] = 0;
    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    auto bellman_ford = [&]() -> bool {
        bool flg = false;
        for(int i =1;i<=n;i++){
            flg = false;
            for(auto [u,v,w]:e){
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
    bellman_ford();
    for(int i = 1;i<=n;i++){
        if(dis[i] == INF) cout<<2147483647LL;
        else cout<<dis[i];
        cout<<" ";
    }
    return 0;
}