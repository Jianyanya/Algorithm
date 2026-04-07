//https://www.luogu.com.cn/problem/P3367
//普通并查集版本
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,sz;
    int cc;

    DSU(int n) :fa(n),sz(n,1),cc(n){
        iota(fa.begin(),fa.end(),0);
    }
    
    int find(int x) { return fa[x] == x?x:fa[x] = find(fa[x]); }

    bool is_same(int x,int y) { return find(x)==find(y); }

    bool merge(int from,int to){
        int x = find(from),y = find(to);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        cc--;
        return true;
    }

    int get_size(int x) { return sz[find(x)]; }
};
int main(){
    int n,m;cin>>n>>m;
    DSU dsu(n+1);
    while(m--){
        int z,x,y;cin>>z>>x>>y;
        if(z==1) dsu.merge(x,y);
        else cout<<(dsu.is_same(x,y)?"Y":"N")<<endl;
    }
    return 0;
}