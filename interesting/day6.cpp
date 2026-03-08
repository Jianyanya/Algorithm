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
    int x,y;cin>>x>>y;
    ve arr(x,ve<int>(y));;
    fo(i,0,x-1){
        fo(j,0,y-1){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,int> mp;
    int flage = 0,ans = -1;
    fo(i,0,x-1){
        fo(j,0,y-1){
            int p = arr[i][j];
            if(mp[p]>=2) continue;
            if((i>0&&arr[i-1][j]==p)||(j>0&&arr[i][j-1]==p)){
                flage = 1;
                mp[p]++;
                ans++;
            }else if(mp[p]==0) mp[p]++,ans++;
        }
    }
    cout<<ans-flage<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}