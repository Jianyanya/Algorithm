//https://atcoder.jp/contests/abc456/tasks/abc456_f
/*
这个题先用暴力表示的话,可以用定长滑窗+dp求最小和
然后dp的转化可以转化为min - plus矩阵乘法
矩阵乘法一出就看固定长度滑动窗口的区间乘积
最后就用用 SWAG 加速滑动窗口矩阵乘积就完成了
同时还可以用线段树进行区间上的乘积维护
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
void jianyanya(){
    int n,k;cin>>n>>k;
    ve<int> arr(n);
    fo(i,0,n-1) cin>>arr[i];
    for(int j = 0,i = 0;i<n;i++){
        
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}