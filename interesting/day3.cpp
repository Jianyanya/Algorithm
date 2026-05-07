//https://codeforces.com/contest/2222/problem/C
/*
动态规划问题
不知道这个中位数具体是多少,我开始想用二分答案的,复杂
首先要看出,每个部分的中位数相同,则整个数组是共用一个中位数的,则原数组的中位数就是各个部分的中位数
怎么统计中位数,用经典贡献法,大于mid为1,等于mid为0,小于mid为-1
至于怎么分段,设计dp(i),来表示前i个数字可划分的最大分段数,我们以最小的数组长度3为基础,从当前向前面进行检查
例:当前为i,检查i-1和i-2是否满足
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
    int n;cin>>n;
    ve<int> arr(n+1),b(n+1);
    fo(i,1,n) cin>>arr[i];
    b = arr;
    sort(b.begin()+1,b.end());
    int mid = b[(n+1)/2];
    fo(i,1,n){
        if(arr[i]==mid){
            arr[i] = 0;
            continue;
        }
        arr[i] = arr[i]>mid?1:-1;
    }
    ve<int> dp(n+1);
    int flg = 0;
    fo(i,1,n){
        dp[i] = 0;
        flg = !arr[i];
        if(flg && (i==1||dp[i-1])) dp[i] = dp[i-1] + 1;
        int sum = arr[i];
        for(int j = i - 3;j>=0;j-=2){
            flg += !arr[j+1] + !arr[j+2];
            sum += arr[j+1] + arr[j+2];
            if(abs(sum) >= flg || (j && !dp[j])) continue;
            dp[i] = max(dp[i],dp[j] + 1);
        }
    }
    cout<<dp[n]<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}