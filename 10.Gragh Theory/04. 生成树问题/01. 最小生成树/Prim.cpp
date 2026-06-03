//https://www.luogu.com.cn/problem/P3366
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

struct Edge{
    int u,v;
    ll w;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<ll> dis(n+1,INF);
    vector<bool> vis(n+1,false);
    ll ans = 0;
    int cnt = 0;
    //朴素Prim算法内存开销很大,所以这个会超内存
    auto Prim1 = [&]() -> void {
        vector<vector<ll> > g(n+1,vector<ll>(n+1,INF));
        for(int i = 0;i<m;i++){
            int u,v;
            ll w;cin>>u>>v>>w;
            g[u][v] = min(g[u][v],w);
            g[v][u] = min(g[v][u],w);
        }
        for(int i = 1;i<=n;i++) g[i][i] = 0;
        dis[1] = 0;
        for(int i = 1;i<=n;i++){
            int u = 0;
            for(int j = 1;j<=n;j++){
                if(!vis[j] && (u == 0 || dis[j] < dis[u])) u = j;
            }
            if(dis[u] == INF){
                cout<<"orz"<<endl;
                return ;
            }
            ans += dis[u];
            vis[u] = true;
            for(int v = 1;v<=n;v++){
                if(!vis[v] && g[u][v] < dis[v]) dis[v] = g[u][v];
            }
        }
        cout<<ans;
    };
    //优先队列实现的Prim算法
    auto Prim_pq = [&]() -> void {
        vector<vector<pair<int,ll> > > g(n+1);
        for(int i = 1;i<=m;i++){
            int u,v;
            ll w;cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto [d,u] = pq.top();pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            ans += d;
            cnt++;
            for(auto [v,w]:g[u]){
                if(vis[v]) continue;
                pq.push({w,v});
            }
        }
        if(cnt < n) cout<<"orz"<<endl;
        else cout<<ans<<endl;
    };
    Prim1();
    Prim_pq();
    return 0;
}