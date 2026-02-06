//cf,题目链接<https://codeforces.com/problemset/problem/1857/E>
/*
关键词：数学
问题分析：
给出一个数组,代表一个线段上的点位,我们要选出这个n个点位为分割点,然后跟每个点进行链接,成n个线段,我们要求,对于每个点位的值,这个值定义为,每个点被线段覆盖的次数

核心思路:
初步思路就是差分+前缀和,这样实现很简单,就是对区间的修改加求区间和,必超时
但是可以一步步分析距离和中的重复部分

数学+排序
其实还是利用了差分思维,我们从第一个元素开始,往右移,可以发现当前的元素离左边元素越远了,离右边元素越近了
右边的n-i个元素距离变短了arr[i]-arr[i-1],左边的i个元素增大了arr[i]-arr[i-1],所以总体减少了(n-2*i)*(arr[i]-arr[i-1])
初始的时候,先算出最左端点离所有点的距离和+n,n为每个点的单独值
处理时要先排序,同时要记录每个点的下标,这样在记录答案时知道原始位置
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
    ve<pair<int,int>> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    ranges::sort(arr,[&](const auto &a,const auto &b){
        if(a.first==b.first) return a.second<b.second;
        else return a.first<b.first;
    });
    ll s = n;
    ve<ll> ans(n);
    for(auto [a,b]:arr){
        s += a - arr[0].first;
    }
    ans[arr[0].second] = s;
    for(int i = 1;i<n;i++){
        s -= 1LL*(n-i*2)*(arr[i].first-arr[i-1].first);
        ans[arr[i].second] = s;
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}