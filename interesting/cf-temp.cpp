#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = long double;
const int MOD=998244353;
const int MX = 1e9;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
const int N = 1e5 + 10;
int T;

int n,m;

void jianyanya(){
    int n,x,s;cin>>n>>x>>s;
    sr str;cin>>str;
    x = min(x,n);
    vector<ll> dp(x + 1,-INF);
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        vector<ll> ndp = dp;
        for(int j = 0;j<=min(x,i);j++){
            if(dp[j] < 0) continue;
            char c = str[i];
            if(c == 'I'){
                if(j < x) ndp[j + 1] = max(ndp[j + 1],dp[j] + 1);
            }else if(c == 'E'){
                if(j > 0 && dp[j] < 1LL*j*s) ndp[j] = max(ndp[j],dp[j] + 1);
            }else{
                if(j < x) ndp[j + 1] = max(ndp[j + 1],dp[j] + 1);
                if(j > 0 && dp[j] < 1LL*j*s) ndp[j] = max(ndp[j],dp[j] + 1);
            }
        }
        dp.swap(ndp);
    }
    ll ans = 0;
    for(int j = 0;j<=x;j++){
        ans = max(ans,dp[j]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}