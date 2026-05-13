//cf,题目链接<https://codeforces.com/contest/2171/problem/C2>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int mod=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve(){
    int n;
    cin >> n;
    ve<ll> a(n+1),b(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i],sum ^= a[i];
    for(int i = 1; i <= n; i++) cin >> b[i],sum ^= b[i];
    int bit = 0;
    int ans = 0;
    if(!sum){
        cout<<"Tie"<<endl;
        return;
    }
    for(int i = 0;i<=20;i++){
        if(sum&1<<i) bit = i;
    }
    for(int i = 1;i<=n;i++){
        if((a[i]^b[i])&1<<bit){
            ans = i;
        }
    } 
    cout<<(ans&1?"Ajisai":"Mai")<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) solve();
    return 0;
}