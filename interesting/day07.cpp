//https://atcoder.jp/contests/abc456/tasks/abc456_e
/*
图论中专门判断环的做法
其中我没有对每个状态进行正确的定义,走不通的点应该标记一下
因为可以自环,无论从哪里都走不通,只要是前面遍历过的点,没得到答案,他就是走不通,这就是标记2的原因
总结: 我们应该标记不可能走通的点,后续关注可能走通的点,由于true和false,只能表达两种状态,不能满足需求,故使用三色标记法
*/
#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = double long;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void jianyanya(){
    int n,m;cin>>n>>m;
    bool flg = false;
    ve<ve<int>> arr(n+1);
    ve<string> wk(n+1);
    fo(i,1,n) arr[i].push_back(i);
    while(m--){
        int u,v;cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int w;cin>>w;
    fo(i,1,n) cin>>wk[i];
    ve<ve<int> > vis(n+1,ve<int>(w,0));
    auto dfs = [&](this auto&& dfs,int id,int day) -> void {
        if(flg) return ;
        vis[id][day] = 1;
        int nd = (day + 1)%w;
        for(auto x:arr[id]){
            if(wk[x][nd] == 'x') continue;
            if(vis[x][nd] == 1){
                flg = true;
                return ;
            }if(vis[x][nd] == 0){
                dfs(x,nd);
                if(flg) return ;
            }
        }
        vis[id][day] = 2;
    };
    fo(i,1,n){
        if(wk[i][0] == 'o' && vis[i][0] == 0){
            dfs(i,0);
        }
        if(flg) break;
    }
    if(flg) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}