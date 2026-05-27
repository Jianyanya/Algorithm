//https://www.luogu.com.cn/problem/P1983
/*
直接按照题目的要求实现即可
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<vector<int> > g(n+1);
    vector<vector<bool> > vis(n+1,vector<bool>(n+1,false));
    vector<int> in(n+1,0);
    int ans = 0;
    while(m--){
        int p;cin>>p;
        vector<bool> cnt(n+1,false);
        int mx = 0,mn = INT_MAX;
        while(p--){
            int t;cin>>t;
            mn = min(t,mn);
            mx = max(t,mx);
            cnt[t] = true;
        }
        for(int i = mn;i<=mx;i++){
            if(!cnt[i]){
                for(int j = mn;j<=mx;j++){
                    if(cnt[j] && !vis[j][i]){
                        vis[j][i] = true;
                        g[j].push_back(i);
                        in[i]++;
                    }
                }
            }
        }
    }
    queue<int> q;
    for(int i = 1;i<=n;i++) if(in[i] == 0) q.push(i);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            auto u = q.front();q.pop();
            for(auto v:g[u]){
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
