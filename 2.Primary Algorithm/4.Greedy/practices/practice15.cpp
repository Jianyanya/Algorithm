//洛谷,题目链接<https://www.luogu.com.cn/problem/P14664>
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
        ll n;
        cin>>n;
        ll a = 0,b = 0;
        for(int bit = 60;bit >= 0;bit--){
            ll m = 1LL<<bit;
            if((n & m)==0){
                ll ta = a|m;
                ll tb = b|m;
                if(ta <= n&&tb <= n){
                    a = ta;
                    b = tb;
                }
            }else{
                if(a < b){
                    ll ta = a|m;
                    if(ta <= n) a = ta;
                    else b |= m;
                }else{
                    ll tb = b|m;
                    if(tb<= n) b = tb;
                    else a |= m;
                }
            }
        }
        cout<<a+b<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}