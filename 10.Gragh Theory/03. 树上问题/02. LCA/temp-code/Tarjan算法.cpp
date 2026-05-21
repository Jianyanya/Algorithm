//https://www.luogu.com.cn/problem/P3379
/*
因为这个模板题会把倍增法卡超时,所以这个题作为离线算法Tarjan算法的模板题
这个做法有点难理解的
我们需要一个并查集来维护每个点的祖先,当我们将一个结点合并进一个集合的时候,通过find可以找到他属于这个集合的祖先
即当前 DFS 过程中，已经处理完成的子树，被压缩到了哪个祖先下面
我们还需要一个vis数组来判断一个结点是否被访问过
我们其实每次处理的时候都是对一个节点的子树进行处理,那么在目前的集合中,该节点更可能是子节点的祖先
所以当我们查询的对象中,有另一个点已经被访问过了,那么这个被访问过的节点和当前正在访问的节点的祖先就是并查集里进行启发式合并的最高祖先
然后在dfs向上递推的时候会出现等级更高的祖先,这时因为已经脱离之前那个子树,所以对于另一个子树里的元素,如果再查询到访问过的节点,那么他们的lca就是这个更高级的祖先
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;cin>>n>>m>>s;
    
    vector<vector<int> > g(n+1);
    vector<int> anstor(n+1,0);
    vector<vector<pair<int,int> > > qry(n+1);
    vector<int> ans(m+1,0);
    vector<int> fa(n+1);
    vector<bool> vis(n+1,false); 
    
    iota(fa.begin(),fa.end(),0);
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        qry[u].push_back({v,i});
        qry[v].push_back({u,i});
    }
    auto find = [&](this auto&& find,int x) -> int {
        return (fa[x] == x)?fa[x]:fa[x] = find(fa[x]);
    };
    auto merge = [&](int x,int y) -> void {
        x = find(x),y = find(y);
        if(x != y) fa[y] = x;
    };
    auto tarjan = [&](this auto&& tarjan,int u,int far) -> void {
        vis[u] = true;
        anstor[find(u)] = u;
        for(auto v:g[u]){
            if(v == far) continue;
            tarjan(v,u);
            merge(u,v);
            anstor[find(u)] = u;
        }
        for(auto [v,id]:qry[u]){
            if(vis[u]){
                ans[id] = anstor[find(v)];
            }
        }
    };
    tarjan(s,0);
    for(int i = 0;i<m;i++) cout<<ans[i]<<endl;
    return 0;
}