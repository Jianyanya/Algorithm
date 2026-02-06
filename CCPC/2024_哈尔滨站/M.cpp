#include <bits/stdc++.h>
using namespace std;
#define ve vector
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
    ll n;
    cin>>n;
    if(n == 1){
        cout<<1<<"\n";
        return;
    }
    ve<ll> d;
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            d.push_back(i);
            if(i * i != n) d.push_back(n / i);
        }
    }
    d.push_back(n);
    sort(d.begin(), d.end());
    ll ans = 0;
    ll pos = 1;
    ll val = n;
    for(ll x:d){
        ll len = x - pos;
        ans += len * val;
        pos = x;
        val = n / x;
    }
    cout<<ans+1<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) solve();
}
