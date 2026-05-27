//https://codeforces.com/problemset/problem/1805/D
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> dis;
int s,t;
void dfs(int u,int fa,int &p){
    for(auto v:g[u]){
        if(v == fa) continue;
        dis[v] = dis[u] + 1;
        if(dis[v] > dis[p]) p = v;
        dfs(v,u,p);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    dis.assign(n+1,0);
    g.assign(n+1,{});
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,s);
    dis.assign(n+1,0);
    dfs(s,0,t);
    vector<int> ds = dis;
    dis.assign(n+1,0);
    int p = 0;
    dfs(t,0,p);
    vector<int> ans(n+1);
    for(int i = 1;i<=n;i++){
        int mx = max(ds[i],dis[i]);
        ans[mx]++;
    }
    cout<<endl;
    int cnt = 0;
    for(int k = 1;k<=n;k++){
        cnt += ans[k - 1];
        cout<<cnt + (cnt < n)<<" ";
    }
    return 0;
}
