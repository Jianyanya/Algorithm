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
void solve(){
    int n;cin>>n;
    ve<ve<int>> arr(n+1);
    fo(i,1,n-1){
        int u,v;cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    ve<int> p(n+1);
    fo(i,1,n) cin>>p[i];
    ve<ve<bool>> memet;
    fo(u,1,n){
        fo(v,u,n){
            ve<int> path(n+1,-1);
            queue<int> q;
            q.push(u);
            path[u] = 0;
            while(!q.empty()){
                    int cur = q.front();q.pop();
                    if(cur==v) break;
                    for(int w:arr[cur]){
                        if(path[w]==-1){
                            path[w] = cur;
                            q.push(w);
                        }
                    }
            }
            ve<bool> mt(n+1,false);
            int cur = v;
            while(cur!=0){
                mt[cur] = true;
                cur = path[cur];
            }
            memet.push_back(mt);
        }
    }
    for(int k = n;k>=1;k--){
        ve<bool> tar(n+1,false);
        fo(i,1,k) tar[p[i]] = true;
        bool flg = false;
        for(auto &mt:memet){
            bool cnt = true;
            fo(i,1,n){
                if(tar[i]&&!mt[i]){
                    cnt = false;
                    break;
                }
            }
            if(cnt){
                flg = true;
                break;
            }
        }
        if(flg){
            cout<<k<<endl;
            return ;
        }
    }
    cout<<1<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}