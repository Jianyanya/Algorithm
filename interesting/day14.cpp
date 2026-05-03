//
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
    ve<ll> arr(n+1);
    fo(i,1,n) cin>>arr[i];
    ve dp(n+1,ve<ll>(n+1,INF));
    dp[1][0] = abs(arr[1]);
    fo(i,1,n-1){
        fo(j,0,i-1){
            if(dp[i][j]==INF) continue;
            dp[i+1][j] = min(dp[i+1][j],dp[i][j] + abs(arr[i+1] - arr[i]));
            ll p = (j==0)?0:arr[j];
            dp[i+1][i] = min(dp[i+1][i],dp[i][j] + abs(arr[i+1] - p));
        }
    }
    ll ans = INF;
    fo(i,0,n-1) ans = min(ans,dp[n][i]);
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}