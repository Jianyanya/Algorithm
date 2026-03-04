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
    ve<int> arr(n),pre(n+1,0);
    fo(i,0,n-1){
        cin>>arr[i];
        pre[i+1] = pre[i] + arr[i];
    }
    sr str;cin>>str;
    int l = 0,r = str.size()-1;
    ll sum = 0;
    while(l<r){
        if(str[l]=='L'&&str[r]=='R'){
            sum += pre[r+1] - pre[l];
            l++;
            r--;
        }
        if(str[l]!='L') l++;
        if(str[r]!='R') r--;
    }
    cout<<sum<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}