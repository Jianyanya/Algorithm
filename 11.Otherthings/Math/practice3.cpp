//https://codeforces.com/contest/2225/problem/D
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
ll mymul(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    while (b) {
        if (b & 1) res = (res + a) % MOD;
        a = (a << 1) % MOD;
        b >>= 1;
    }
    return res%MOD;
}
ll cnt(ll L, ll R, int k){
    if(L > R) return 0;
    return (R - k + 4) / 4 - ((L - 1 - k + 4) / 4);
}
void solve(){
    ll n, x;
    cin>>n>>x;
    ll left1 = cnt(1, x-1, 1);
    ll right1 = cnt(x, n, 1);
    ll left3 = cnt(1, x-1, 3);
    ll right3 = cnt(x, n, 3);
    ll ans = 0;
    ans = (ans + (left1%MOD)*(right1%MOD)) % MOD;
    ans = (ans + (left3%MOD)*(right3%MOD)) % MOD;
    ans = (ans + right3) % MOD;
    cout<<ans%MOD<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}