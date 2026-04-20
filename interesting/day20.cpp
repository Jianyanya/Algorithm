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
    int n,m;cin>>n>>m;
    ve<ll> arr(n+1);
    fo(i,1,n) cin>>arr[i];
    ll flg = 1;
    ll pre = -1,cnt = 0;
    fo(i,1,n){
        if(arr[i] != pre){
            cnt =0;
            pre = arr[i];
        }
        cnt++;
        if(cnt>=m) flg = 0;
    }
    if(flg) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}