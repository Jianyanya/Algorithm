//https://www.luogu.com.cn/problem/B2173
#include<bits/stdc++.h>
using namespace std;

int n,v;
int main(){
    cin>>n>>v;
    vector arr(n,vector<int>(3,0));
    for(int i = 0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    //简单方法,就是在完全背包上加了个次数的限制,看起来很简单,这是橙题解法
    auto f1 = [&]() -> int {
        vector<int> dp(v+1,0);
        for(int i = 0;i<n;i++){
            for(int w = v;w>=arr[i][0];w--){
                for(int c = 0;c<=arr[i][2]&&c*arr[i][0]<=w;c++){
                    dp[w] = max(dp[w],dp[w-c*arr[i][0]]+c*arr[i][1]);
                }
            }
        }
        return dp[v];
    };
    //二进制分组优化,绿题解法
    auto f2 = [&]() -> int {
        vector<int> dp(v+1,0);
        for(int i = 0;i<n;i++){
            int val = arr[i][1],w = arr[i][0],c = arr[i][2];
        for(int k = 1;c>0;k<<=1){
            int t = min(k,c);
            int weight = w*t;
            int value = val*t;
            for(int j = val;j>=weight;j--){
                dp[j] = max(dp[j],dp[j-weight]+value);
            }
            c -= t;
        }
    }
    return dp[v];
    };
    //单调队列优化
    auto f3 = [&]() -> int {
        
    };
    return 0;
}