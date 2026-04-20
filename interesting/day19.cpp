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
    int n;cin>>n;
    ve<int> arr(n),cnt(110,0);
    bool flg = false;
    fo(i,0,n-1){
        cin>>arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]]>1) flg = true;
    }
    if(flg){
        cout<<-1<<endl;
        return ;
    }
    ranges::sort(arr,greater());
    fo(i,0,n-1) cout<<arr[i]<<" ";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}