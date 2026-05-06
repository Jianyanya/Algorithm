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
void jianyanya () { 
    int n ; cin >> n ;
    ve <ll> a ( n );
    ll mx = 0 ;
    fo ( i , 0 , n - 1 ){
        cin >> a [ i ];
        mx = max ( mx , a [ i ]);
    }
    ve <ll> b ;
    b.push_back(mx);
    bool flg = false;
    for(ll x :a) {
        if (x == mx && !flg) {
            flg = true;
            continue;
        }
        b.push_back(x);
    }
    sort(b.begin() + 1, b.end());
     ll ans = 0;
    int mex = 0;
    ve<bool> vis(n + 2, false);
    fo ( i , 0 , n - 1 ){
        if (b[i] <= n) vis[b[i]] = true;
        while (vis[mex]) mex++;
        ans += mex + mx;
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}