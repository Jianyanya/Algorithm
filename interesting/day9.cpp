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
const int N = 10;
int cl[9] = {0};
ve arr(N,ve<char>(N));
int n,k,ans = 0,cnt = 0;
void dfs(int id,int s){
    if(id>n){
        ans += s==k;
        return;
    }
    for(int i = 0;i<n;i++){
        if(arr[id][i]=='#'&&cl[i]==0){
            cl[i] = 1;
            dfs(id+1,s+1);
            cl[i] = 0;
        }
    }
    dfs(id+1,s);
}
void solve(){
    while(cin>>n>>k&&(n!=-1&&k!=-1)){
        cnt = 0;
        ans = 0;
        memset(cl,0,sizeof(cl));
        fo(i,0,n-1){
            fo(j,0,n-1){
                cin>>arr[i][j];
                if(arr[i][j]=='#') cnt++;
            }
        }
        if(cnt==k) cout<<1<<endl;
        else{
            dfs(0,0);
            cout<<ans<<endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}