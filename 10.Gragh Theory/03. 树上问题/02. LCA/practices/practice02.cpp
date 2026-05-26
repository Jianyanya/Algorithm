//https://www.luogu.com.cn/problem/P4281
/*
考察对lca和树上点距的理解
这里给出一个模型让你推导
    a
    |
    o
   / \
  b   c
题目要求a,b,c相遇最少消耗,无疑在中间最少,那么就是lca(a,b)和lca(a,c)还有lca(b,c)的点,
看看我们要求的长度到底是多少,就是子树(a,b,c)的边数
根据lca的性质可得出
dist(a,b) = dis[a] + dis[b] - 2*dis[lca(a,b)];
dist(a,c) = dis[a] + dis[c] - 2*dis[lca(a,c)];
dist(b,c) = dis[b] + dis[c] - 2*dis[lca(b,c)];
相加得 2*(dis[a] + dis[b] + dis[c] - dis[lca(a,b) - dis[lca(a,c)] - dis[lca(b,c)]])
这样就得出了怎么计算该子树边长,如果有不同边权值,则需要单独计算depth和dis的值
这个中心就是三个公共最近祖先深度最高的
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int v,id,kind;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) : fa(n),sz(n,1){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x] == x?fa[x]:fa[x] = find(fa[x]);
    }

    bool merge(int x,int y){
        x = find(x),y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;cin>>n>>m;
    vector<int> anstor(n+1,0),depth(n+1,0);
    vector<vector<Edge> > qry(n+1);
    vector<vector<int> > g(n+1);
    //ab = 0,ac = 1,bc = 2;
    vector<array<int,3> > arr(m+1),lcares(m);
    vector<bool> vis(n+1,false);
    DSU dsu(n+1);
    
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        arr[i][0] = a,arr[i][1] = b,arr[i][2] = c;
        qry[a].push_back({b,i,0});
        qry[b].push_back({a,i,0});
        qry[a].push_back({c,i,1});
        qry[c].push_back({a,i,1});
        qry[b].push_back({c,i,2});
        qry[c].push_back({b,i,2});
    }
    auto tarjan = [&](this auto&& tarjan,int u,int fa) -> void {
        depth[u] = depth[fa] + 1;
        anstor[u] = u;
        for(auto v:g[u]){
            if(v == fa) continue;
            depth[v] = depth[u] + 1;
            tarjan(v,u);
            dsu.merge(u,v);
            anstor[dsu.find(u)] = u;
        }
        vis[u] = true;
        for(auto [v,id,kind]:qry[u]){
            if(!vis[v]) continue;
            lcares[id][kind] = anstor[dsu.find(v)]; 
        }
    };
    tarjan(1,0);
    for(int i = 0;i<m;i++){
        int x = lcares[i][0],y = lcares[i][1],z = lcares[i][2];
        int a = arr[i][0],b = arr[i][1],c = arr[i][2];
        int w = x;
        if(depth[y] > depth[w]) w = y;
        if(depth[z] > depth[w]) w = z;
        int val = depth[a] + depth[b] + depth[c] - depth[x] - depth[y] - depth[z];
        cout<<w<<" "<<val<<endl;
    }
    return 0;
}
