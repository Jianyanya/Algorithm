//https://www.luogu.com.cn/problem/P2195
/*
求直径 + 并查集维护每个点之间的直径
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e5 + 10;

vector<int> fa;
int find(int x) { return fa[x] == x?x:fa[x] = find(fa[x]); }

int main(){
    int n,m,q;cin>>n>>m>>q;
    vector<vector<int> > g(n+1);
    vector<int> dis(n+1,0);
    vector<int> mxs(n+1,0);
    vector<int> len(n+1,0);
    vector<int> vis(n+1,0);
    fa.assign(n+1,0);
    iota(fa.begin(),fa.end(),0);
    while(m--){
        int u,v;cin>>u>>v;
        fa[find(u)] = find(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int t = 0;
    int cnt = 0;
    auto dfs = [&](this auto&& dfs,int u,int fa) -> void {
        int m1 = -1,m2 = -1;
        for(auto v:g[u]){
            if(v == fa) continue;
            dfs(v,u);
            int temp = dis[v] + 1;
            dis[u] = max(dis[u],temp);
            if(temp > m1) m2 = m1,m1 = temp;
            else if(temp > m2) m2 = temp;
        }
        mxs[u] = max(max(0,m1 + m2),max(m1,m2));
        cnt = max(cnt,mxs[u]);
    };
    auto f = [&](int x) -> void {
        cnt = 0;
        dfs(x,0);
        len[x] = cnt;
    };
    for(int i = 1;i<=n;i++){
        if(fa[i] != i || vis[i]) continue;
        f(i);
        vis[i] = 1;
    }
    while(q--){
        int k;cin>>k;
        if(k == 1){
            int s;cin>>s;
            cout<<len[find(s)]<<endl;
        }else{
            int x,y;cin>>x>>y;
            x = find(x),y = find(y);
            if(x == y) continue;
            int p = ((len[x] + 1)>>1) + ((len[y] + 1)>>1) + 1;
            p = max(p,max(len[x],len[y]));
            fa[find(x)] = find(y);
            len[find(x)] = p;
        }
    }
    return 0;
}