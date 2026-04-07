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
    ve<int> a(n),b(n);
    fo(i,0,n-1) cin>>a[i];
    fo(i,0,n-1) cin>>b[i];
    ll ans = 1;
    for(int i = n-1;i>0;i--){
        if((a[i]>=a[i-1]&&a[i]>=b[i-1])&&(b[i]>=a[i-1]&&b[i]>=b[i-1])) ans = (ans*2)%MOD;
    }
    cout<<ans*2%MOD<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}