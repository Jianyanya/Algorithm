//https://www.luogu.com.cn/problem/P8805
#include<bits/stdc++.h>
using namespace std;

vector<int> fa,sz;

int find(int x){
    return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
}

void merge(int x,int y){
    x = find(x),y = find(y);
    if(x != y) fa[y] = x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    fa.assign(n+1,0),sz.assign(n+1,1);
    iota(fa.begin(),fa.end(),0);
    vector<vector<int> > g(n+1);
    vector<int> val(n+1,0);
    vector<int> dis(n+1,0);
    vector<vector<pair<int,int> > > qry(n+1);
    vector<bool> vis(n+1,false);
    vector<int> anstor(n+1,0);
    vector<int> ans(m);
    vector<pair<int,int> > arr(m);

    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        val[u]++;
        val[v]++;
    }
    for(int i = 1;i<=n;i++) dis[i] = val[i];
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        arr[i] = {u,v};
        qry[u].push_back({v,i});
        qry[v].push_back({u,i});
    }
    auto tarjan = [&](this auto&& tarjan,int u,int far) -> void {
        vis[u] = true;
        anstor[find(u)] = u;
        for(auto v:g[u]){
            if(v == far) continue;
            dis[v] += dis[u];
            tarjan(v,u);
            merge(u,v);
            anstor[find(u)] = u;
        }
        for(auto [v,id]:qry[u]){
            if(vis[v]){
                ans[id] = anstor[find(v)];
            }
        }
    };
    tarjan(1,0);
    for(int i = 0;i<m;i++){
        int w = ans[i];
        auto [u,v] = arr[i];
        int t = dis[u] + dis[v] - 2*dis[w] + val[w];
        cout<<t<<endl;
    }
    return 0;
}