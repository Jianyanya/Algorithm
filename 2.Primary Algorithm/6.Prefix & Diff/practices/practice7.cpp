//cf,题目链接<https://codeforces.com/contest/2158/problem/C>
/*
这个问题就是求非空子数组的最大和
关键词：贪心 前后缀
问题分析：
给出两个数组a,b,要正好进行k回游戏,对方每次都能进行一次操作,将b[i]加或者减到a[i](同位置的)
最后结果为a数组中最大的非空子数组和(连续),Alice要最大化结果,bob要最小化结果
双方都为最优策略

核心思路:
首先先解决博弈论的普遍问题,真的要进行k回合吗?
显然不是,对于Alice来说,她选择的是最优的,对bob就是最坏的,所以bob一定要抵消Alice的操作,于是进行k次就看是抵消了(k为偶数)
还是Alice进行了一次操作(k为奇数)使a数组有最大的非空子数组和
抵消了的情况好说,而且Alice可以减或者加,b可能为负数,所以加b的绝对值,所以问题变为
对数组进行一次加a[i]+|b[i]|之后数组的最大非空数组和
我不知道加哪个位置,故枚举位置,计算最大前缀和和最大后缀和就行了
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
    ll n,k;cin>>n>>k;
    ve<ll> a(n),b(n),pre(n),suf(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    pre[0] = a[0];
    for(int i = 1;i<n;i++){
        pre[i] = (pre[i-1]>0?pre[i-1]:0LL)+a[i];
    }
    suf[n-1] = a[n-1];
    for(int i = n-2;i>=0;i--){
        suf[i] = (suf[i+1]>0?suf[i+1]:0LL)+a[i];
    }
    k&=1;
    ll ans = LLONG_MIN;
    if(k==0){
        ans = *max_element(pre.begin(),pre.end());
        cout<<ans;
    }else{
        for(int i = 0;i<n;i++){
            ans = max(ans,pre[i]+suf[i]-a[i]+abs(b[i]));
        }
        cout<<ans;
    }
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}