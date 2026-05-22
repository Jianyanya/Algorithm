//https://www.luogu.com.cn/problem/P3128
/*
经典树上点差分模板题
还是前缀和的模式,对树上的一个区间进行增加,利用lca找到两个点的最短路径
跟线性差分的模式其实一样,在开头加的位置加上+x,在结尾-x
我们看lca倍增法的过程其实就好理解了,从u和v两个点向上找最近公共祖先,那么u和v就是开头,lca(u,v)就是结尾
于是有val[u] += x,val[v] += x,val[lca(u,v)] -= x,因为是u,v两个向上累加,所以lca(u,v)这里-x保证只加了一次x,然后val[fa[lca(u,v)]]还要减去x
*/
#include<bits/stdc++.h>
using namespace std;
const int LOG = 31;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    vector<int> val(n+1,0);
    vector<vector<int> > g(n+1);
    vector<int> depth(n+1,0);
    vector<vector<int> > f(n+1,vector<int>(LOG + 1,0));
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](this auto&& dfs,int u,int fa) -> void {
        f[u][0] = fa;
        depth[u] = depth[fa] + 1;
        for(int i = 1;i<=LOG;i++){
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs(v,u);
        }
    };
    auto lca = [&](int u,int v) -> int {
        if(depth[u] < depth[v]) swap(u,v);
        for(int i = LOG - 1;i>=0;i--){
            if(depth[f[u][i]] >= depth[v]) u = f[u][i];
        }
        if(u == v) return u;
        for(int i = LOG - 1;i>=0;i--){
            if(f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    };
    dfs(1,0);
    auto add_path = [&](int u,int v) -> void {
        int w = lca(u,v);
        val[u]++;
        val[v]++;
        val[w]--;
        if(f[w][0]) val[f[w][0]]--;
    };
    auto dfs2 = [&](this auto&& dfs2,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs2(v,u);
            val[u] += val[v];
        }
        ans = max(ans,val[u]);
    };
    while(k--){
        int s,t;cin>>s>>t;
        add_path(s,t);
    }
    dfs2(1,0);
    cout<<ans;
    return 0;
}