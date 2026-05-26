/*
这个是经典回溯算法
输入说明：输入第一行给出三个正整数，分别表示地下迷宫的节点数N、边数M和探索起始节点编号S。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号。
输出说明：若可以点亮所有节点的灯，则输出从S开始并以S结束的包含所有节点的序列，序列中相邻的节点一定有边；否则虽然不能点亮所有节点的灯，但还是输出点亮部分灯的节点序列，最后输出0，此时表示迷宫不是连通图。
由于深度优先遍历的节点序列是不唯一的，为了使得输出具有唯一的结果，我们约定以节点小编号优先的次序访问。在点亮所有可以点亮的灯后，以原路返回的方式回到起点。
样例输入:
8 10 3
1 2
2 6
6 4
4 7
1 7
1 5
3 5
3 4
4 5
7 8
输出:
3 4 5 1 2 6 2 1 7 8 7 1 5 4 3
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;cin>>n>>m>>s;
    vector<vector<int> > g(n+1);
    vector<int> ans;
    vector<bool> vis(n+1,false);

    while(m--){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) ranges::sort(g[i]);
    auto dfs = [&](this auto&& dfs,int u) -> void {
        ans.push_back(u);
        vis[u] = true;
        for(int v:g[u]){
            if(vis[v]) continue;
            dfs(v);
            ans.push_back(u);
        }
    };
    dfs(s);
    //判断是否连通,如果连通,通过一个点的dfs,一定能遍历到所有点
    for(int i = 1;i<=n;i++)
        if(!vis[i]){
            ans.push_back(0);
            break;
        }
    for(int x:ans) cout<<x<<" ";
    return 0;
}
