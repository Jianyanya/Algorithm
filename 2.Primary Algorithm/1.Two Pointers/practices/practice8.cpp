//洛谷,题目链接<https://www.luogu.com.cn/problem/P14576>
/*
滑动窗口
在尾部的光标越多越好,那么我就在每行后面都加上光标
那么现在就是尽可能的把所有的光标聚集到最长行
转换一下,把最长行看成一个窗口,我们要滑动窗口使这个窗口内的光标最多
记录每个光标的位置,把问题转化成一条线上的滑窗
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
    int n;cin>>n;
    ve<ll> arr(n+1),pre(n+1);
    ll mx = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        pre[i] = pre[i-1] + arr[i] + 1;
        mx = max(mx,arr[i]);
    }
    int ans = 0;
    for(int l = 1,r = 1;r<=n;r++){
        while(l<r&&(pre[r] - pre[l])>mx) l++;
        ans = max(r-l+1,ans);
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}