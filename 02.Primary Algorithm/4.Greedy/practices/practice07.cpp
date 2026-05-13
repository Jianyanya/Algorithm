//cf,题目链接<https://codeforces.com/contest/2170/problem/C>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
struct cmp{
    bool operator()(int a, int b) const {
        return a > b;
    }
};
void solve(){
    ll n,k;cin>>n>>k;
    ve<ll> q(n),r(n);
    for(int i = 0;i<n;i++) cin>>q[i];
    for(int i = 0;i<n;i++) cin>>r[i];
    sort(q.begin(),q.end(),cmp());
    sort(r.begin(),r.end());
    ll id = 0,id2 = 0;
    ll ans = 0;
    while(id<n&&id2<n){
        while(id<n){
            ll cur = q[id]*(r[id2]+1)+r[id2];
            id++;
            if(cur<=k){
            ans++;
            id2++;
            break;
            }
        }
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}