//https://www.luogu.com.cn/problem/P2014
/*
树形背包dp板子
设 f[u,i,j]为表示以 u 号点为根的子树中，已经遍历了 u 号点的前 i 棵子树，选了 j 门课程的最大学分
转移方程 : f[u,i,j] = max(f[u,i,j],f[u][i - 1][j - k] + f[v][s_v][k]),(v,k<=j,k<=siz),siz为以u为根节点的子树大小;
利用滚动数组去除二维之后,f[u][k]为当前已经处理过若干个儿子后，在 u 的子树里选 x 个点的最大价值
转移方程 : f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<int> s(n+1);
    vector<vector<int> > g(n+1);
    vector<vector<int> > dp(n+1,vector<int>(2*n+1,0));
    for(int i = 1;i<=n;i++){
        int k;cin>>k>>s[i];
        g[k].push_back(i);
    }
    auto dfs = [&](this auto&& dfs,int u) -> int {
        int len = 1;
        dp[u][1] = s[u];//首先要选了这个课程才能继续选下面的
        for(auto v:g[u]){
            int sz = dfs(v);//收集子树大小
            //转移方程部分
            for(int i = min(len,m + 1);i;i--){
                for(int j = 1;j<=sz && j + i <= m + 1;j++){
                    dp[u][i+j] = max(dp[u][i+j],dp[u][i] + dp[v][j]);
                }
            }
            len += sz;
        }
        return len;
    };
    dfs(0);
    cout<<dp[0][m + 1];
    return 0;
}