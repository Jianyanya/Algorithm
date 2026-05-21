//https://www.luogu.com.cn/problem/P3379
/*
这里介绍一种利用欧拉序列将lca转化为区间最小值问题的解法
原理很简单,就是求出该树的欧拉序列,然后求出要查询的u和v第一次出现的位置的对应区间的最小值
对于这棵树,我们求出
欧拉序列 : 1, 2, 4, 2, 5, 2, 1, 3, 1
对应深度 : 1, 2, 3, 2, 3, 2, 1, 2, 1
结点第一次出现的位置
pos[1]=1,pos[2]=2,pos[4]=3,pos[5]=5,pos[3]=8;
求lca(4,5),pos[4] = 3,pos[5] = 5,欧拉序区间[3,5] = 4,2,5,深度最小的是2,于是最近公共祖先就是2
    1
   / \
  2   3
 / \
4   5
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;cin>>n>>m>>s;

    vector<vector<int> > g(n+1);
    vector<int> depth(n<<1,0);
    vector<int> arr(n<<1);
    vector<int> pos(n+1,0);
    vector<int> lg(n<<1);
    vector<vector<int> > st(30,vector<int>(n<<1));
    vector<vector<int> > rev(30,vector<int>(n<<1));
    int id = 0;

    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](this auto&& dfs,int u,int dep) -> void {
        arr[++id] = u;
        depth[id] = dep;
        pos[u] = id;
        for(auto v:g[u]){
            if(pos[v]) continue;
            dfs(v,dep+1);
            arr[++id] = u;
            depth[id] = dep;
        }
    };
    auto init = [&]() -> void {
        for(int i = 1;i<=id;i++){
            lg[i] = lg[i>>1] + 1;
        }
        for(int i = 1;i<=id;i++){
            st[0][i] = depth[i];
            rev[0][i] = arr[i];
        }
        for(int k = 1;k<=lg[id];k++){
            for(int i = 1;i+(1<<k)-1 <= id;i++){
                int left = i;
                int right = i + (1<<(k - 1));
                if(st[k - 1][left] <= st[k - 1][right]){
                    st[k][i] = st[k - 1][left];
                    rev[k][i] = rev[k - 1][left];
                }else{
                    st[k][i] = st[k - 1][right];
                    rev[k][i] = rev[k - 1][right];
                }
            }
        }
    };
    auto qry = [&](int l,int r) -> int {
        if(l > r) swap(l,r);
        int k = lg[r - l + 1];
        int left = l;
        int right = r - (1<<k) + 1;
        return st[k][left] <= st[k][right]?rev[k][left]:rev[k][right];
    };
    auto lca = [&](int u,int v) -> int {
        return qry(pos[u],pos[v]);
    };
    dfs(s,0);
    init();
    while(m--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}