//高精度加法
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve(){
    sr str1,str2;cin>>str1>>str2;
    int a = str1.size(),b = str2.size();
    int len = max(a,b);
    while(str1.size()<len) str1 = '0'+str1;
    while(str2.size()<len) str2 = '0'+str2;
    int t = 0;
    sr ans = "";
    for(int i = len-1;i>=0;i--){
        int w = str1[i] - '0' + str2[i] - '0' + t;
        t = w/10;
        w = w%10;
        char c = '0' + w;
        ans = c+ans;
    }
    if(t!=0) ans = '1'+ans;
    cout<<ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}