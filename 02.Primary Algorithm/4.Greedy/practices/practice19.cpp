//https://codeforces.com/contest/2222/problem/B
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
    int n,m;cin>>n>>m;
    ve<pair<int,int>> arr;
    ve<int> vis(n+1,0);
    ll ans = 0;
    fo(i,1,n){
        int p;cin>>p;
        arr.emplace_back(p,i);
        ans += p;
    }
    ranges::sort(arr,greater());
    ll sum = 0;
    fo(i,0,m-1){
        int p;cin>>p;
        bool flg = false;
        for(auto [a,b]:arr){
            int k = abs(p - b)+1;
            //cout<<k<<endl;
            if(k%2||p==b){
                if(a<0&&flg) break;
                flg = true;
                if(a>=0&&vis[b]) continue;
                if(vis[b]!=1) sum += a;
                //cout<<a<<endl;
                vis[b] = 1;
                break;
            }
        }
    }
    cout<<ans - sum<<endl;
    //cout<<"-----------------"<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}