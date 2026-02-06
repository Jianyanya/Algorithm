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
int n,m;
void solve(){
    cin>>n;
    ve<ll> a(n+1,LLONG_MAX);
    fo(i,0,n-1) cin>>a[i];
    cin>>m;
    ve<ll>  b(m+1,LLONG_MAX);
    fo(i,0,m-1) cin>>b[i];
    ll suma = 3*n,sumb = 3*m;
    ll i = 0,j = 0,ansa = suma,ansb = sumb;
    while(i<n||j<m){
        if(a[i]<b[j]){
            if(i<n) i++;
            suma--;
            if(suma-sumb>ansa-ansb) ansa = suma,ansb = sumb;
        }else{
            if(j<m) j++;
            sumb--;
            if(suma-sumb>ansa-ansb) ansa = suma,ansb = sumb;
        }
    }
    cout<<ansa<<':'<<ansb;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}