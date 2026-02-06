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
    int n,m,k;cin>>n>>m>>k;
    ve<ve<int>> arr(n+1),ans(n+1);
    ve<bool> memt(n+1,false);
    ve<int> st(n+1,0);
    for(int i = 0;i<k;i++){ 
        int a;cin>>a;
        st[a] = 2;
    }
    for(int i = 0;i<m;i++){
        int a,b;cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int cnt= 0 ;
    for(int i = 1;i<=n;i++){
        if(st[i]==2) continue;
        memt[i] = true;
        for(int x:arr[i]){
            if(memt[i]) continue;
            ans[i].push_back(x);
        }
        if(!ans[i].empty()) cnt++;
    }
    cout<<"Yes"<<endl;
    cout<<cnt<<endl;
    for(int i = 1;i<n;i++){
        if(ans[i].empty()) continue;
        cout<<i<<" "<<ans[i].size()<<" ";
        for(int x:ans[i]) cout<<x<<" ";
        cout<<endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}