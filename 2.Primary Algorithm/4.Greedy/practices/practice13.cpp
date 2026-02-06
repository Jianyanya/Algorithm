//区间贪心
//小笨的序列染色
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