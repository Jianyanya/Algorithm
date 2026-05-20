//https://www.luogu.com.cn/problem/B4016
/*
求树的直径的双向dfs做法
此处还有树形dp的做法,(一个数组做树形dp或者利用双数组)
*/
#include<bits/stdc++.h>
using namespace std;
int n, t = 0,d = 0;
vector<vector<int> > g;
vector<int> dis;
vector<int> d1,d2;
vector<int> dp;
//双向dfs
void dfs2(int u,int fa){
    for(auto v:g[u]){
        if(v == fa) continue;
        dis[v] = dis[u] + 1;
        if(dis[v] > dis[t]) t = v;
        dfs2(v,u);
    }
}
//双数组dp,找到一个点的主长子链和次长子链
void dfs(int u,int fa){
    d1[u] = d2[u] = 0;
    for(auto v:g[u]){
        if(v == fa) continue;
        dfs(v,u);
        t = dis[v] + 1;
        if(t > d1[u]) d2[u] = d1[u],d1[u] = t;
        else if(t > d2[u]) d2[u] = t;
    }
    d = max(d,d1[u] + d2[u]);
    return ;
}
//单数组实现的树形dp
void dps(int u,int fa){
    for(auto v:g[u]){
        if(v == fa) continue;
        dfs(v,u);
        d = max(d,dp[u] + dp[v] + 1);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}
int main(){
    cin>>n;
    g.assign(n+1,{});
    dis.assign(n+1,0);
    d1.assign(n+1,0);
    d2.assign(n+1,0);
    dp.assign(n+1,0);
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //双dfs
    {
        dfs2(1,0);
        dis[t] = 0;
        dfs2(t,0);
        cout<<dis[t];
    }
    //双数组树形dp
    {
        dfs(1,0);
        cout<<d<<endl;
    }
    //树形dp
    {
        dps(1,0);
        cout<<d<<endl;
    }
    return 0;
}