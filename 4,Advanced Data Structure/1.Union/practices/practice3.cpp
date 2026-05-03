//https://www.luogu.com.cn/problem/P1197
/*
这个题问,每删除一个点之后,此时连通块的数量为多少,这个看起来像是在线操作,但实际不是
我一开始使用的是经典的带删除并查集,可是回顾一下我之前学习的带删除操作的并查集,他的根本难点在于解决删除的点是根节点的问题
即删除根节点,这个点的子节点也会被删除,但是虚拟节点只解决了这个问题,没有真正的删除这个点,整个集合仍然是一个整体,没有分裂
"删除"只是把元素从一个集合移动到另一个集合,不会导致集合内部产生分裂(因为集合是无结构的,元素之间没有依赖关系),这就是*集合划分问题*
现在这个题是图连通问题,删除某个点会导致分裂,那么我们要知道并查集擅长的是合并操作,而非分裂,所以我们从逆向思考
我们先假设删除所有点,然后再看要分裂的点合并的时候能连通多少个连通块
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

struct DSU{
    vector<int> fa,sz;

    DSU(int n) :fa(n),sz(n,1){
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
    vector<vector<int>> grid(n+1);
    vector<pair<int,int>> arr(m);
    for(int i = 0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
        grid[arr[i].first].push_back(arr[i].second);
        grid[arr[i].second].push_back(arr[i].first);
    }
    int k;cin>>k;
    vector<int> nodes(k+1),ans(k+1);
    vector<bool> vis(n+1,false);
    for(int i = 0;i<k;i++){
        cin>>nodes[i];
        vis[nodes[i]] = true;
    }
    DSU dsu(n+1);
    int cc = n - k;
    for(auto [a,b]:arr){
        if(!vis[a]&&!vis[b]){
            if(dsu.merge(a,b)) cc--;
        }
    }
    ans[k] = cc;
    for(int i = k-1;i>=0;i--){
        int node = nodes[i];
        vis[node] = false;
        cc++;
        for(auto x:grid[node]){
            if(!vis[x]){
                if(dsu.merge(node,x)) cc--;
            }
        }
        ans[i] = cc;
    }
    for(int i = 0;i<=k;i++) cout<<ans[i]<<endl;
    return 0;
}