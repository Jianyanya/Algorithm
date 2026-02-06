//洛谷,题目链接<https://www.luogu.com.cn/problem/P14665>
/*

*/
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
    int n,m;cin>>n>>m;
    ve<int> arr(n+1),cur(n+1);
    int mx = -1,mn = INT_MAX;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        cur[i] = arr[i] - arr[i-1];
        mx = max(arr[i],mx);
        mn = min(arr[i],mn);
    }
    auto check = [&](int mid) -> bool {
        int nmx = 0,nmn = 0,ans1 = 0,ans2 = 0;
        for(int i = 2;i<=n;i++){
            nmx = max(cur[i],nmx+cur[i]);
            nmn = min(cur[i],nmn+cur[i]);
            if(nmx>mid) ans1 += nmx - mid,nmn -= nmx - mid,nmx = mid;
            if(-nmn>mid) ans2 += -nmn - mid,nmx += -nmn - mid,nmn = -mid;
        }
        return max(ans1,ans2)<=m;
    };
    int l = 0,r = mx - mn;
    while(l<r){
        int mid = l+(r-l)/2;
        if(check(mid)) r = mid;
        else l = mid + 1; 
    }
    cout<<r;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}