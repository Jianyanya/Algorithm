//https://www.luogu.com.cn/problem/P3258
#include<bits/stdc++.h>
using namespace std;
const int LOG = 31;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    vector<int> val(n+1,0);
    vector<vector<int> > g(n+1);
    vector<int> depth(n+1,0);
    vector<vector<int> > f(n+1,vector<int>(LOG + 1,0));
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
        val[f[v][0]]++;
        val[w]--;
        if(f[w][0]) val[f[w][0]]--;
    };
    auto dfs2 = [&](this auto&& dfs2,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs2(v,u);
            val[u] += val[v];
        }
    };
    for(int i = 0;i<n-1;i++){
        add_path(arr[i],arr[i+1]);
    }
    dfs2(1,0);
    for(int i = 1;i<=n;i++) cout<<val[i]<<endl;
    return 0;
}