//洛谷,题目链接<https://www.luogu.com.cn/problem/P1627>
/*
还是数字大小贡献的问题,去掉奇数限制是这个题:lc<https://leetcode.cn/problems/count-subarrays-with-median-k/description/>
*/
#include <bits/stdc++.h>
using namespace std;
#define ve vector
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
    int n,b;cin>>n>>b;
    ve<int> arr(n);
    ve<ll> pre(n+1);
    int id = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==b) id = i,arr[i] = 0;
        else if(arr[i]>b) arr[i] = 1;
        else if(arr[i]<b) arr[i] = -1;
        pre[i+1] = pre[i] + arr[i];
    }
    //for(int x:pre) cout<<x<<" ";
    //cout<<endl;
    unordered_map<ll,ve<int>> mp;
    int ans = 0;
    for(int i = 0;i<=n;i++){
        if(i>=id){
            auto ita = mp.find(pre[i]);
            auto itb = mp.find(pre[i]-1);
            if(ita!=mp.end()){
                for(int x:ita->second){
                    if((i-x)%2) ans++;
                }
            }
            if(itb!=mp.end()){
                for(int x:itb->second){
                    if((i-x)%2==0) ans++;
                }
            }
        }
        mp[pre[i]].push_back(i);
    }
    cout<<ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}