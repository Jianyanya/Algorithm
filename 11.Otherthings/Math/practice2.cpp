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
    ll ans = 0;
    cout<<(1<<n) - 1<<" ";
    fo(i,1,n){
        for(int j = 0;j<(1<<i);j+=2){
            int res = j*(1<<(n-i)) + (1<<(n-i)) - 1;
            cout<<res<<" ";
        }
    }
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}