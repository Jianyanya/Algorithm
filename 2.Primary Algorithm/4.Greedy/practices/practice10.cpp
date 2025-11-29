//cf,题目链接<https://codeforces.com/contest/2170/problem/B>
/*

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
    int n;
    cin>>n;
    ve<int> arr(n);
    ll sum =0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(),arr.end());
    int l = 0,r = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>0){
            l = i;
            break;
        }
    }
    for(int i = n-1;i>=0;i--){
        if(arr[i]>0){
            r = i;
            break;
        }
    }
    int len = r-l+1;
    if(sum-n+1>=len) cout<<len;
    else cout<<sum-n+1;
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}