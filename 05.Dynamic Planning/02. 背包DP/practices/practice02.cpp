//https://www.luogu.com.cn/problem/P8806
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<array<int,2> > arr(n);
    int mx = 0;
    for(int i = 0;i<n;i++){
        int w,v;cin>>w>>v;
        arr[i] = {w,v};
        mx = max(mx,w+v);
    }
    sort(arr.begin(),arr.end(),[&](const auto&a,const auto&b){
        return a[1] + a[0] < b[1] + b[0];
    });
    int ans = 0;
    vector<int> dp(mx+1,0);
    for(int i = 0;i<n;i++){
        for(int j = arr[i][0] + arr[i][1];j>=arr[i][0];j--){
            dp[j] = max(dp[j],dp[j-arr[i][0]] + arr[i][1]);
            ans = max(dp[j],ans);
        }
    }
    cout<<ans;
    return 0;
}