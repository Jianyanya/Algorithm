//区间贪心
//小笨的序列染色
/*
题目描述:
小苯有一个长度为 n 的序列 {a1, a2, . . . , an}，他可以对 a 做如下操作：
选择 l, r(1 ⩽ l ⩽ r ⩽ n) 满足：区间端点的最大值恰好等于区间长度(即 max(al, ar) = r − l + 1)
则小苯可通过一次操作染红 [l, r] 区间中的所有元素。（注意，每个数字可以被重复染色）
你的任务就是求出，最少需要几次操作，可以将整个序列的所有元素全部染红；或者报告无法做到。
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
    ve<int> arr(n+1);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    ve<int> indexs(n+1);
    for(int i = 1;i<=n;i++){
        int r = i+arr[i]-1;
        if(r<=n&&arr[i]>=arr[r]) indexs[i] = max(indexs[i],r);
    }
    for(int i = 1;i<=n;i++){
        int l = i-arr[i]+1;
        if(l>=1&&arr[i]>=arr[l]) indexs[l] = max(indexs[l],i);
    }
    int ans = 0,ed = 0,fist = 0;
    for(int i = 1;i<=n;i++){
        fist = max(fist,indexs[i]);
        if(i>ed){
            if(i>fist){
                cout<<-1<<endl;
                return ;
            }
            ans++;
            ed = fist;
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