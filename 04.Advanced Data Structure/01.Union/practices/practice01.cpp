//https://www.luogu.com.cn/problem/P2024
/*
    食物链
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 3;

struct DSU{
    vector<int> fa,sz,dist;
    
    DSU(int n) : fa(n),sz(n,1),dist(n){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        if(fa[x] == x) return x;
        int y = find(fa[x]);
        dist[x] = (dist[x] + dist[fa[x]])%mod;
        return fa[x] = y;
    }

    bool merge(int from,int to,int d){
        find(from),find(to);
        d = (d + mod - dist[to])%mod;
        d = (d + dist[from])%mod;
        int x = fa[from],y = fa[to];
        if(x == y) return d==0;
        if(sz[x]<sz[y]){
            swap(x,y);
            d = (mod - d)%mod;
        }
        sz[x] += sz[y];
        fa[y] = x;
        dist[y] = d;
        return true;
    }
};
int main(){
    int n,k;cin>>n>>k;
    DSU dsu(n+1);
    int res = 0;
    while(k--){
        int p,x,y;cin>>p>>x>>y;
        if(x>n||y>n){
            res++;
            continue;
        }
        res += !dsu.merge(x,y,p==1?0:1);
    }
    cout<<res;
    return 0;
}