#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T;
//直接枚举
void solve(){
    int n;cin>>n;
    int l = n/4,r = n/2;
    int ans = 0;
    for(int i = 0;i<=l;i++){
        for(int j = 0;j<=r;j++){
            if(i*4+j*2==n) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}