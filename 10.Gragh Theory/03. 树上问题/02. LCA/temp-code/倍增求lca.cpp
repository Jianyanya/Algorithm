//https://acm.hdu.edu.cn/showproblem.php?pid=2586
/*
该题在基础的求lca基础上求树上两点的最短距离
该题实现的lca为基础的倍增算法
我们可以使用lca的性质来计算该大小,当p为u和v的祖先时
有dis[u] + dis[v] - 2*dis[p],其中dis[i]表示为i到根节点的距离
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<utility>//poj不能用
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
const int LOG = 31;
    
vector<vector<pair<int,ll>> > g;
vector<vector<int> > f;
vector<int> depth;
vector<ll> dis;
void dfs(int u,int fa){
        f[u][0] = fa;
        depth[u] = depth[fa] + 1;
        for(int i = 1;i<=LOG;i++){
            f[u][i] = f[f[u][i-1]][i-1];
        }
        for(auto p:g[u]){
            int v = p.first;
            ll w = p.second;
            if(v == fa) continue;
            dis[v] = dis[u] + w;
            dfs(v,u);
        }
    }
int lca(int u,int v){
    if(depth[u] < depth[v]) swap(u,v);
    for(int i = LOG - 1;i>=0;i--){
        if(depth[f[u][i]] >= depth[v]) u = f[u][i];
    }if(u == v) return u;
    for(int i = LOG - 1;i>=0;i--){
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
ll dist(int u,int v){
    int p = lca(u,v);
    return dis[u] + dis[v] - 2*dis[p];
}
void jianyanya(){
    int n,m;cin>>n>>m;
    g.assign(n+1,{});
    f.assign(n+1,vector<int>(LOG + 1));
    depth.assign(n+1,0);
    dis.assign(n+1,0);
    for(int i = 1;i<n;i++){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    while(m--){
        int u,v;cin>>u>>v;
        cout<<dist(u,v)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) jianyanya();
    return 0;
}