//https://www.luogu.com.cn/problem/P10931
/*
树上边差分问题
实际上还是套用的点差分问题的模板,重点在点差的细节处理
我感觉都是一个固定的模板关键就在于对题目需求的理解和add_path的实现
对于这个题,有n-1条主边,就意味着每个结点相连接形成无向无环图,那么切任何一条主边都能分割成两部分
那么剩下来的附加边就是形成环的关键,当我们切了该附加边形成环中的任何一个主边,再切除该附加边得到一个方案
于是,该附加边形成的环上每个主边都能得到一个方案,我们将n-1个边的权值存在n-1个点中(除根结点),转化为点差问题
最后累加2 ~ n结点的值就行
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
        val[w] -= 2;
    };
    auto dfs2 = [&](this auto&& dfs2,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs2(v,u);
            val[u] += val[v];
        }
    };
    for(int i = 0;i<k;i++){
        int s,t;cin>>s>>t;
        add_path(s,t);
    }
    dfs2(1,0);
    for(int i = 2;i<=n;i++) ans += (val[i] == 0?k:(val[i] == 1));
    cout<<ans;
    return 0;
}