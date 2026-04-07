//https://vjudge.net/problem/Yosupo-unionfind_with_potential
//带权并查集,题目可能有点难看懂
/*
我们要存的就是题目给出的两个数的关系,如果我没有学过并查集,可能我要使用很多变量来维持关系,并每次遍历整体来更新关系
这样时间复杂度太高,于是我们把两个数看作树的节点,相连接就是有关系,这个结果就是边权值
实现路径压缩,计算子节点到根节点的距离(边权总和),比如a和b的根节点为c,那么a到b的值就为a到c与b到c的差,由于之前实现了路径压缩,所以计算很快
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

struct DSU{
    vector<int> fa,sz,dis;

    DSU(int n) : fa(n),sz(n,1),dis(n){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        if(fa[x]!=x){
            int y = find(fa[x]);
            dis[x] = (dis[x] + dis[fa[x]])%MOD;
            fa[x] = y;
        }
        return fa[x];
    }

    bool merge(int from,int to,int d){
        //这一步是先进行路径压缩
        int x = find(from),y = find(to);
        d = (d + MOD - dis[to])%MOD;
        d = (d + dis[from])%MOD;
        if (x == y) return d == 0;
        if(sz[x]<sz[y]){
            swap(x,y);
            d = (MOD - d)%MOD;
        }
        fa[y] = x;
        sz[x] += sz[y];
        dis[y] = d;
        return true;
    }

    int query(int x,int y){
        find(x),find(y);
        if(fa[x]!=fa[y]) return -1;
        return (dis[y] - dis[x] + MOD)%MOD;
    }
};
int main(){
    int n,m;cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int t;cin>>t;
        if(t){
            int u,v;cin>>u>>v;
            cout<<dsu.query(u,v)<<endl;
        }else{
            int u,v,x;cin>>u>>v>>x;
            cout<<(dsu.merge(u,v,x)?1:0)<<endl;
        }
    }
    return 0;
}