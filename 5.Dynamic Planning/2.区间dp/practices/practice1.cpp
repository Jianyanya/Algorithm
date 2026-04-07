//https://www.luogu.com.cn/problem/P1388
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
    int n,k;cin>>n>>k;
    ve<int> arr(n+1);
    ve dp(n+1,ve(n+1,ve<int>(k+1,-1)));
    fo(i,1,n){
        cin>>arr[i];
        dp[i][i][0] = arr[i];
    }
    //枚举区间长度
    fo(len,2,n){
        //枚举左端点,r = len + l - 1 <=n;l <= n - len + 1;
        fo(l,1,n-len+1){
            int r = len + l - 1;
            //枚举乘号个数,数量不能超过k和len-1,两个数之间一个符号
            fo(t,0,min(k,len-1)){
                //枚举分割点
                fo(m,l,r-1){
                    //要讨论左部分有多少乘号,讨论中间是乘号还是加号
                    //中间为加号
                    fo(a,0,min(t,m-1)){
                        int b = t - a;
                        if(b>r-m - 1) continue;
                        if(dp[l][m][a]!=-1&&dp[m+1][r][b]!=-1) dp[l][r][t] = max(dp[l][r][t],dp[l][m][a]+dp[m+1][r][b]);
                    }
                    //中间为乘号,初始t==1;
                    if(t>=1){
                        fo(a,0,min(t - 1,m-1)){
                            int b = t - a - 1;
                            if(b>r-m - 1) continue;
                            if(dp[l][m][a]!=-1&&dp[m+1][r][b]!=-1) dp[l][r][t] = max(dp[l][r][t],dp[l][m][a]*dp[m+1][r][b]);
                        }
                    }
                }
            }
        }
    }
    cout<<dp[1][n][k];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}