//https://www.luogu.com.cn/problem/P1462
/*
这个题看似很简单,可以直接用dfs做,但是会超时
怎么考虑优化,其实并不是所有的点都需要搜索,我们从1到n,其实答案的范围就在[max(f[1],f[n]),max({f[1],f[2],f[3]....f[n]})]中
当我们选择了一个答案之后,可以选择不经过大于这个答案的路径,只要这个路径存在,答案一定不大于他
再以路径的条数看,一开始取最大的答案,有10条路径被搜索,当我们缩小答案,则可能只有5条,最后只剩下1条(该条可以取到最小的最大值)
这样就发现有单调性,可以二分答案 + Dijkstra去判断到n的最短路的消耗血量是否小于总血量
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

int main(){
    int n,m,b;cin>>n>>m>>b;
    vector<vector<pair<int,ll> > > g(n+1);
    vector<bool> vis(n+1,false);
    vector<ll> f(n+1);
    ll l = 0,r = 0;
    for(int i = 1;i<=n;i++){
        cin>>f[i];
        r = max(r,f[i]);
    }
    l = max(f[1],f[n]);
    while(m--){
        int u,v;
        ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    auto check = [&](ll mx) -> bool {
        if(f[1] > mx || f[n] > mx) return false;
        priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
        vector<ll> dis(n+1,INF);
        dis[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            auto [d,u] = pq.top();pq.pop();
            if(d != dis[u]) continue;
            if(d > b) continue;
            for(auto [v,w]:g[u]){
                if(f[v] > mx) continue;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
        return dis[n] <= b;
    };
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r - l)/2;
        if(check(mid)) r = mid - 1,ans = mid;
        else l = mid + 1;
    }
    if(ans == -1) cout<<"AFK";
    else cout<<ans<<endl;
    return 0;
}