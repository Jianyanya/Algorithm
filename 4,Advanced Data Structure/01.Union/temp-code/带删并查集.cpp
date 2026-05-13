//https://www.spoj.com/problems/JMFILTER/
//带删除操作的并查集,其原理和添加操作一样
//正常删除一个节点,如果该节点是根节点,则会删除该节点的所有子节点,明显不行
//正常添加一个节点,如果该节点是根节点,则会添加该节点的所有子节点,明显不行
//这两个问题有一个共通性,就是"如果该节点不为根节点就可以随意操作了"
//问题就在根节点上,所以我直接让其不为根节点,设置一个虚拟节点当作任何节点的根节点,这样就可以随意进行添加和删除操作了
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,sz;
    int id,cc;

    DSU(int n,int m) : id(n*2),fa(2*n+m),sz(2*n+m,1),cc(n){
        iota(fa.begin(),fa.begin() + n,n);
        iota(fa.begin() + n,fa.end(),n);
    }

    int find(int x) {return fa[x]==x?x:fa[x] = find(fa[x]);}

    bool is_same(int x,int y) {return find(x)==find(y);}

    bool merge(int from,int to){
        int x = find(from),y = find(to);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
        cc--;
        return true;
    }

    int get_size(int x) {return sz[find(x)];}

    void erase(int x){
        int y = find(x);
        int old = sz[y];
        sz[y]--;
        int root = id++;
        fa[x] = root;
        fa[root] = root;
        sz[root] = 1;
        if(old==1) ;
        else cc++;
    }
};
int n,m,case_id = 0;                                                  
int main(){
    while((cin>>n>>m),n){
        //这里有个大忌,初始化的时候一定要按照题目下标,从0开始,不然会导致虚拟节点映射错位
        DSU dsu(n,m);
        while(m--){
            char c;cin>>c;
            if(c=='M'){
                int x,y;cin>>x>>y;
                dsu.merge(x,y);
            }else if(c=='S'){
                int x;cin>>x;
                dsu.erase(x);
            }
        }
        cout<<"Case #"<<(++case_id)<<": "<<dsu.cc<<"\n";
    }
    return 0;
}