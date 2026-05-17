//https://www.luogu.com.cn/problem/P1144
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 100003;
const long long INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<ll> ans(n+1,0),dis(n+1,-1);
    vector<vector<int> > g(n+1);
    queue<int> q;
    while(m--){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis[1] = 0;
    ans[1] = 1;
    q.push(1);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v:g[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                ans[v] = ans[u];
                q.push(v);
            }else if(dis[v] == dis[u] + 1) ans[v] = (ans[v] + ans[u])%MOD;
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]%MOD<<endl;
    }
    return 0;
}