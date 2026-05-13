//cf,题目链接<https://codeforces.com/contest/2173/problem/C>
/*
贪心,构造,数学

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
    int n,k;cin>>n>>k;
    ve<int> arr(n);
    map<int,int> mp,cnt;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    if(n==k){
        bool flage = true;
        for(int i = 1;i<=n;i++){
            if(mp.count(i)) continue;
            flage = false;
            break;
        }
        if(flage){
            cout<<1<<endl;
            cout<<1<<endl;
            return;
        }
        // else{
        //     cout<<-1<<endl;
        //     return ;
        // }
    }
    ve<int> ans;
    ranges::sort(arr);
    for(int i = 0;i<n;i++){
        int x = arr[i];
        if(cnt.count(x)) continue;
        for(int j = x;j<=k;j+=x){
            if(!mp.count(j)){
                cout<<-1<<endl;
                return;
            }
        }
        for(int j = x;j<=k;j+=x) cnt[j]++;
        ans.push_back(x);
    }
    cout<<ans.size()<<endl;
    ranges::sort(ans);
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}