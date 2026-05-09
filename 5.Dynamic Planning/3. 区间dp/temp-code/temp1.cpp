//https://loj.ac/p/10147
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> pre(2*n+1,0),arr(n+1,0);
    vector dp(2*n+1,vector<int>(2*n+1,0));
    vector dp2(2*n+1,vector<int>(2*n+1,0));
    int i = 1;
    for(;i<=n;i++){
        cin>>arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    for(;i<=2*n;i++){
        pre[i] = pre[i-1] + arr[i-n];
    }
    for(int len = 2;len<=n;len++){
        for(int l = 1;l<=2*n - len;l++){
            int r = len + l - 1;
            dp2[l][r] = INT_MAX;
            for(int k = l;k<r;k++){
                dp[l][r] = max(dp[l][r],dp[l][k]+dp[k+1][r]+pre[r] - pre[l-1]);
                dp2[l][r] = min(dp2[l][r],dp2[l][k]+dp2[k+1][r]+pre[r] - pre[l-1]);
            }
        }
    }
    int mn = INT_MAX, mx = 0;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, dp2[i][i + n - 1]);
        mx = max(mx, dp[i][i + n - 1]);
    }
    cout << mn << endl << mx;
    return 0;
    return 0;
}