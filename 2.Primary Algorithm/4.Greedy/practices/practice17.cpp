//cf,题目链接<https://codeforces.com/contest/2178/problem/C>
//一个很简单,但是又让我气愤的题
/*
说白了,就是这么的一个问题
给你一个问题
初始值x = 0,给出一列数据(数量为n),这些数据中有正有负,你可以把这组数据看成一个链表
我们每次必须选择该链表第一个或者第二个数据,选择第一个数据就将该数据加到x上,选择第二个数据就要使x减去该数据
我们要进行n-1次操作,使x最大,选择如何数据后都要从该链表删除该数据
*/
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
    ve<ll> arr(n+1),pre(n+1),suf(n+1);
    fo(i,1,n){
        cin>>arr[i];
        pre[i] = pre[i-1] + abs(arr[i]);
    }
    for(int i = n-1;i>=0;i--){
        suf[i] = suf[i+1] - arr[i+1];
    }
    ll ans = LLONG_MIN;
    for(int i = 1;i<=n;i++){
        int a1 = arr[i];
        if(i==1) ans = max(ans,suf[i]);
        else ans = max(ans,arr[1] + pre[i-1] - pre[1] + suf[i]);
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}