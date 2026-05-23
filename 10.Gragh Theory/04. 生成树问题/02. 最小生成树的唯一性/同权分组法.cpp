//http://poj.org/problem?id=1679
/*
sum1 = 当前权值组里，连接不同旧连通块的边数
sum2 = Kruskal 实际在这一组里选了几条边
当sum1 != sum2 的时候,说明这组同权候选边在旧连通块缩点图里形成了环,因此可以替换,MST 不唯一
候选边数 > 能选进森林的边数
=> 有环
=> 同权边可替换
=> MST 不唯一
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v;
    ll w;
};

struct DSU{
    vector<int> fa,sz;

    DSU(int n) :fa(n),sz(n,1){
        iota(fa.begin(),fa.end(),0);
    }
    
    int find(int x) { return fa[x] == x?x:fa[x] = find(fa[x]); }

    bool merge(int from,int to){
        int x = find(from),y = find(to);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int n,m;
void solve(){
    cin>>n>>m;
    vector<Edge> e(m);
    for(int i = 0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end(),[&](const auto&a,const auto&b){
        return a.w < b.w;
    });
    DSU dsu(n+1);
    ll ans = 0;
    bool flg = true;
    for(int l = 0;l<m;){
        int r = l;
        while(r < m && e[r].w == e[l].w) r++;
        int sum1 = 0,sum2 = 0;
        for(int i = l;i<r;i++){
            if(dsu.find(e[i].u) != dsu.find(e[i].v)) sum1++;
        }
        for(int i = l;i<r;i++){
            if(dsu.merge(e[i].u,e[i].v)){
                ans += e[i].w;
                sum2++;
            }
        }
        if(sum1 != sum2){
            flg = false;
            break;
        }
        l = r;
    }
    if(flg) cout<<ans<<endl;
    else cout<<"Not Unique!"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}