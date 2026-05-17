//https://www.luogu.com.cn/problem/P3371
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

int main(){
    int n,m,s;cin>>n>>m>>s;
    vector<vector<pair<int,int> > > e(m);
    vector<ll> dis(n+1,INF);
    vector<int> cnt(n+1,0),vis(n+1,0);
    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u].emplace_back(v,w);
    }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    cnt[s] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = 0;
        for(auto [v,w]:e[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    vis[v] = 1;
                    cnt[v]++;
                    q.push(v);
                    if(cnt[v]>=n) goto br;
                }
            }
        }
    }
    br:;
    for(int i = 1;i<=n;i++){
        if(dis[i] == INF) cout<<2147483647;
        else cout<<dis[i];
        cout<<" ";
    }
    return 0;
}