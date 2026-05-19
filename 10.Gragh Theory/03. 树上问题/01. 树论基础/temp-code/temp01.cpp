//https://www.luogu.com.cn/problem/B4016
/*
求树的直径的双向dfs做法
此处还有树形dp的做法,(一个数组做树形dp或者利用双数组)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int> > g(n+1);
    vector<int> dis(n+1,0);
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int t = 0;
    auto dfs = [&](this auto&& dfs,int u,int fa) -> void {
        for(auto v:g[u]){
            if(v == fa) continue;
            dis[v] = dis[u] + 1;
            if(dis[v] > dis[t]) t = v;
            dfs(v,u);
        }
    };
    dfs(1,0);
    dis[t] = 0;
    dfs(t,0);
    cout<<dis[t];
    return 0;
}