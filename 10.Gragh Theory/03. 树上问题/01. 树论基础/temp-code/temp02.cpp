/*
求树的中心
一个树的中心满足,树的直径必定经过的点
即该点为父节点的最长子链中有最短子链的点就为中点

维护d1[x]为向下子树中子链最长的
维护d2[x]为向下子树中子链次长的
维护up[x]为非向下子树中子链最长的(重点: 非向下子树即不在该子树节点中,继续向上扩展后可向下转向)
答案就是比较上下子树中最长中的最短子链的点
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
const long long INF = 1e18;

vector<ll> d1(N),d2(N),up(N);
vector<vector<pair<int,ll> > > g(N);
ll x = 0,y = 0,ans = LLONG_MAX;

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    auto dfsd = [&](this auto&& dfsd,int u,int fa) -> void {
        for(auto [v,w]:g[u]){
            if(v == fa) continue;;
            dfsd(v,u);
            if(d1[v] + w > d1[u]){
                d2[u] = d1[u];
                d1[u] = d1[v] + w;
            }else if(d1[v] + w > d2[u]){
                d2[u] = d1[v] + w;
            }
        }
    };
    auto dfsu = [&](this auto&& dfsu,int u,int fa) -> void {
        for(auto [v,w]:g[u]){
            if(v == fa) continue;
            up[v] = up[u] + w;
            if(d1[v] + w != d1[u]) up[v] = max(up[v],d1[u] + w);//不在该子树节点中
            else up[v] = max(up[v],d2[u] + w);
            dfsu(v,u);
        }
    };
    dfsd(1,0);
    dfsu(1,0);
    for(int i = 1;i<=n;i++){
        if(max(up[i],d1[i]) < ans){
            ans = max(up[i],d1[i]);
            x = i;
            y = 0;
        }else if(max(up[i],d1[i]) == ans) y = i;
    }
    if(y == 0) cout<<"该树只有一个中心: "<<x<<endl;
    else cout<<"该树有两个中心: "<<x<<" "<<y<<endl;
    return 0;
}