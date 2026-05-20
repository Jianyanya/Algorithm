/*
树的重心有三个定义,我们可以利用这三个定义来求树的重心
1. 在树中删去结点 v 后，得到的图 𝑇 ∖{𝑣} 中每个连通分量的大小均不超过原树结点数的一半．
2. 在所有删去某个结点后得到的最大连通分量大小中，删去结点 v 时所得到的值最小．
3. 树中所有结点到某个结点的距离和中，到结点 v 的距离和最小．
除上述定义外还有以下性质
1. 树的重心如果不唯一，则恰有两个．这两个重心相邻．而且，删去它们的连边后，树将变为两个大小相同的连通分量．
2. 在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离．
3. 把两棵树通过一条边相连得到一棵新的树，那么新树的重心在连接原来两棵树的重心的路径上．
4. 一棵有根树的重心一定在根结点所在的重链上．一棵树的重心一定是该树根结点重子结点对应子树的重心的祖先．
*/
/*
先介绍第一个dfs经典求重心的方法,这个方法就是基于定义1实现的,我们求每个点的子树大小,假如该点被删除后形成两个子树大小
形象的我们叫做下面的树大小sz,那么我们可以通过n - sz就计算出上面树的大小

第二种就是换根dp了,利用定义3,其原理很简单,在我的动态规划/树形dp/temp03中有详细做法
只不过该题是要求最小深度,反过来就行

wiki给了道cf1900分数的例题,吓哭了,还是当练习要求做吧
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<int> > g(n+1);
    vector<ll> sz(n+1,0);
    vector<ll> depth(n+1,0);
    vector<ll> dp(n+1,0);
    vector<int> ans;
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //dfs做法
    auto dfs = [&](this auto&& dfs,int u,int fa) -> void {
        sz[u] = 1;
        depth[u] = 0;
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs(v,u);
            sz[u] += sz[v];
            depth[u] = max(depth[u],sz[v]);
        }
        depth[u] = max(depth[u],n - sz[u]);
        if(depth[u] <= n/2) ans.push_back(u);
    };
    //换根dp做法
    auto dfs1 = [&](this auto&& dfs,int u,int fa) -> void {
        sz[u] = 1;
        depth[u] = depth[fa] + 1;
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs(v,u);
            sz[u] += sz[v];
        }
        return ;
    };
    auto get_ans = [&](this auto&& get_ans,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dp[u] = dp[u],dp[u] + n - 2*sz[v];
            dfs(v,u);
        }
    };
    //dfs做法
    {
        dfs(1,0);
        for(int x:ans) cout<<x<<" ";
    }
    //换根dp
    {
        dfs1(1,0);
        ll sum = 0;
        for(int i = 1;i<=n;i++) sum += sz[i];
        dp[1] = sum;
        get_ans(1,0);
        int res = INT_MAX;
        for(int i = 1;i<=n;i++){
            if(dp[i] < res){
                res = dp[i];
                ans = {i};
            }else if(dp[i] == res) ans.push_back(i);
        }
        for(int x:ans) cout<<x<<" ";
    }
    return 0;
}