//https://www.luogu.com.cn/problem/P1892
/*
这个题就是关于并查集中反集的例题
第一次做很难想出来,但是还是有思考价值的
首先,朋友的朋友就是朋友,这很好想,都是一个集合就行
但是关于敌人,敌人的敌人就是朋友怎么判断
我们可以这样想,这就像是一个相互关系,a -> b(朋友),b -> a(朋友)处于一个集合且不用特殊处理
但是,a -> b(敌人),b -> a(敌人),需要特殊处理,不如再继续写
可以,a -> c(敌人),c -> a(敌人),所以b和c是朋友,这里就可以发现,a有一个敌人的集合,且处于敌人集合中的元素都为朋友,且该集合与a无直接联系(只统计朋友集合)
怎么把a与该集合分开但不实际分开呢,说法有点矛盾,但这不就是虚拟节点的应用吗,在删除操作中,对x进行虚拟节点的映射,做出删除操作,实际未删除
这里可以利用虚拟节点,把a的敌人都映射到a + n的集合中,即实现操作
a 和 b + n合并,b 和 a + n合并
a 和 c + n合并,c 和 a + n合并
这样b和c就到一个集合中了
*/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,sz;

    DSU(int n) :fa(2*n),sz(2*n,1){
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
        return true;
    }

    int get_size(int x) { return sz[find(x)]; }
};
int main(){
    int n,m;cin>>n>>m;
    DSU dsu(n + 1);
    while(m--){
        char c;
        int u,v;cin>>c>>u>>v;
        if(c=='F') dsu.merge(u,v);
        else{
            dsu.merge(u,v + n);
            dsu.merge(v,u + n);
        }
    }
    unordered_set<int> st;
    for(int i = 1;i<=n;i++){
        st.insert(dsu.find(i));
    }
    cout<<st.size();
    return 0;
}