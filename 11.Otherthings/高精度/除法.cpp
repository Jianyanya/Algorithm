//高精度除法
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
    string s,ans = "";
    ll b;cin>>s>>b;
    int t = 0;
    for(int i = 0;i<s.size();i++){
        int w = (t*10+(s[i]-'0'))/b;
        ans += '0' + w;
        t = (t*10+(s[i]-'0'))%b;
    }
    int id= 0;
    while(id<ans.size()&&ans[id]=='0') id++;
    for(int i = id;i<ans.size();i++){
        cout<<ans[i];
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}