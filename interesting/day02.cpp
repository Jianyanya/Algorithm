#include<bits/stdc++.h>
using namespace std;
//问题: 将数字n分解为k个不相同的正整数之和,问有多少种分解的方法?
/*
2022 10
379187662194355221
*/
/*
首先我们要把问题转化一下,这里是k个不相同的正整数,那么保证每个数都不相同的话,我们考虑最小的时候
a1 < a2 < a3 < .. < a10
令bi = ai - (i - 1);
这样bi也满足b1 < b2 < b3 < ... < b10
那么求和得
sum(a) = sum(b) + (0 + 1 + 2 + .. + 9) = sum(b) + 45;
那么就是求sum(a) 分解为k个数(此时可以相等,无序)
1. 就是整数分拆理论中的将 n 拆成恰好 k 个正整数之和（顺序无关）的方法数
2. 动态规划: 记dp[i][j]为将i分解为j个整数之和的方案数
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ans = 0;
    int n,k;cin>>n>>k;
    int res = (k-1)*k/2;
    n -= res;
    vector<vector<long long> > dp(n+1,vector<long long>(k+1,0));
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=max(1,k);j++){
            dp[i][j] = dp[i - 1][j - 1] + (i>j?dp[i - j][j]:0);
        }
    }
    cout<<dp[n][k];
    return 0;
}