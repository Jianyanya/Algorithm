//https://codeforces.com/problemset/problem/685/B
/*
根据"把两棵树通过一条边相连得到一棵新的树，那么新树的重心在连接原来两棵树的重心的路径上．"
利用已知重心求子树的重心
求重心的过程我看来更像性质2,因为添加子节点的操作和向上和父节点合并的操作是一样的
就是对于一颗树的重心，当对其添加一个节点的时候，该树的重心最多移动一次，且沿着父节点移动
这就是该解法中从子树的重心沿着向上搜索的第一个满足条件的点一定为重心
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    vector<int> fa(n+1);
    vector<vector<int> > g(n+1);
    vector<int> ans(n+1,0);
    vector<int> sz(n+1,0);
    vector<int> dis(n+1,0);
    for(int i = 2;i<=n;i++){
        cin>>fa[i];
        g[fa[i]].push_back(i);
    }
    auto dfs = [&](this auto&& dfs,int u) -> void {
        sz[u] = 1;
        ans[u] = u;
        for(auto v:g[u]){
            dfs(v);
            sz[u] += sz[v];
            dis[u] = max(dis[u],sz[v]);
        }
        for(auto v:g[u]){
            int p = ans[v];
            while(p != u){
                if(max(dis[p],sz[u] - sz[p]) <= sz[u]/2){
                    ans[u] = p;
                    break;
                }else p = fa[p];
            }
        }
    };
    dfs(1);
    while(q--){
        int u;cin>>u;
        cout<<ans[u]<<endl;
    }
    return 0;
}