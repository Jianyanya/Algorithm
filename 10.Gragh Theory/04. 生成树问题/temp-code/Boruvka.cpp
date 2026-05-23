//https://www.luogu.com.cn/problem/P3366
/*
这里给出Boruvka算法的模板
这个算法的实现逻辑就是每次连接两个连通块之间最小的边,批量处理边
首先把每个点都当作一个连通块,然后找到每个连通块连接的最小边
再对每个连通块找到的最小边进行合并连通块就行了
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

struct Edge{
    int u,v;
    ll w;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) : fa(n),sz(n,1){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
    }

    bool merge(int x,int y){
        x = find(x),y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int com = n;
    ll ans = 0;
    int cnt = 0;
    vector<Edge> e(m);
    DSU dsu(n+1);
    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    while(com > 1){
        vector<int> best(n+1,-1);
        for(int i = 0;i<m;i++){
            int u = dsu.find(e[i].u);
            int v = dsu.find(e[i].v);
            if(u == v) continue;
            if(best[u] == -1 || e[i].w < e[best[u]].w) best[u] = i;
            if(best[v] == -1 || e[i].w < e[best[v]].w) best[v] = i;
        }
        bool flg = false;
        for(int i = 1;i<=n;i++){
            if(best[i] == -1) continue;
            int id = best[i];
            int u = e[id].u;
            int v = e[id].v;
            ll w = e[id].w;
            if(dsu.merge(u,v)){
                ans += w;
                cnt++;
                com--;
                flg = true;
            }
        }
        if(!flg){
            cout<<"orz"<<endl;
            return 0;
        }
    }
    if(cnt != n - 1) cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}