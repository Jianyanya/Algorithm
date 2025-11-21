#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
/*
想法一:
记录后缀异或和sufa和sufb
然后遍历数组记录sumA和sumB
奇数时每次比较sumA^a[i]^sufa[i+1]和sumA^b[i]^sufa[i+1]谁大
偶数原理相同
比较问题:
sumA^a[i]^sufa[i+1]和sumB^b[i]^sufb[i+1];
*/
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
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}