//洛谷,题目链接<https://www.luogu.com.cn/problem/P1314>
/*
二分答案 前缀和
这个s是ll,把我坑死了
*/
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
    ll n,m,s;cin>>n>>m>>s;
    ve<ll> ws(n+1),p(n+1),ls(m+1),rs(m+1);
    int mx = 0;
    for(int i = 1;i<=n;i++){
        cin>>ws[i]>>p[i];
        mx = max((int)ws[i],mx);
    }
    for(int i = 0;i<m;i++){
        cin>>ls[i]>>rs[i];
    }
    ll ans_sum = LLONG_MAX;
    auto check = [&](int w) -> ll {
        ve<ll> cnt(n+1,0),prices(n+1,0);
        for(int i = 1;i<=n;i++){
            cnt[i] = cnt[i-1];
            prices[i] = prices[i-1];
            if(ws[i]>=w){
                cnt[i]++;
                prices[i] += p[i];
            }
        }
        ll y = 0;
        for(int i = 0;i<m;i++){
            int l = ls[i],r = rs[i];
            y += 1LL*(cnt[r] - cnt[l-1])*(prices[r] - prices[l-1]);
        }
        return y;
    };
    int left = 0,right = mx;
    while(left<=right){
        int mid = left+(right-left)/2;
        ll y = check(mid);
        ans_sum = min(ans_sum,llabs(s-y));
        if(y<s) right = mid-1;
        else left = mid + 1;
    }
    cout<<ans_sum;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}