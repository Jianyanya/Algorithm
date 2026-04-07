//https://vjudge.net/problem/UVA-11987
//实现添加操作的并查集
//这个题还要输出集合总和,所以在并查集内维护一个sum数组就行,在合并和删除的时候进行加减
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,sz,sum;
    int id,cc;

    DSU(int n,int m) : id(n*2),fa(2*n+m),sz(2*n+m,1),cc(n),sum(2*n+m,0){
        iota(sum.begin()+n,sum.end(),1);
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
        sum[x] += sum[y];
        cc--;
        return true;
    }

    int get_size(int x) {return sz[find(x)];}

    void erase(int x){
        int y = find(x);
        sz[y]--;
        sum[y] -= x;
        int new_root = id++;
        fa[x] = new_root;
        fa[new_root] = new_root;
        sum[new_root] = x;
    }

    void split(int x,int y){
        int a = find(x),b = find(y);
        if(a==b) return;
        sz[a]--,sum[a] -= x+1,sum[b] += x+1,sz[b]++,fa[x] = b;
    }
};
int n,m;                                                  
int main(){
    //注意题目给出的下标,我的模板默认是从1开始,这个题目给出0-based的话要进行-1操作
    while(cin>>n>>m){
        DSU dsu(n,m);
        while(m--){
            int k;cin>>k;
            if(k==3){
                int x;cin>>x;
                int y = dsu.find(x-1);
                cout<<dsu.sz[y]<<" "<<dsu.sum[y]<<endl;
            }else{
                int x,y;cin>>x>>y;
                if(k==1) dsu.merge(x-1,y-1);
                else dsu.split(x-1,y-1);
            }
        }
    }
    return 0;
}