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
int T;

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
ve<ll> fac,ifac;
ll C(int n,int m){
    if(m<0||m>n) return 0;
    return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
void jianyanya(){
    int x1,x2,x3;cin>>x1>>x2>>x3;
    int k = x2 + 1;
    int maxN=max({x1 + x2,x3 + x2,k});
    fac.assign(maxN + 1,1);
    ifac.assign(maxN + 1,1);
    fo(i,1,maxN) fac[i] = fac[i-1]*i%MOD;
    ifac[maxN] = qpow(fac[maxN],MOD-2);
    for(int i = maxN;i >= 1;i--) ifac[i-1] = ifac[i]*i%MOD;
    ll ans=0;
    int lim = min({x1,x3,k});
    fo(t,0,lim){
        ll val = C(k,t);
        val = val*C(k+x1-t-1,x1-t)%MOD;
        val = val*C(k+x3-t-1,x3-t)%MOD;
        if(t&1) ans = (ans-val+MOD)%MOD;
        else ans = (ans+val)%MOD;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T=1;
    while(T--) jianyanya();
}