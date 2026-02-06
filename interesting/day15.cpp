
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
const int N = 2e5 + 10;
int a[N], now[N], pos[N], xi[N], fir[N], lst[N], nxt[N];
void solve(){
    int n, m, k;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin >> a[i], now[i] = a[i];
    for(int i = 1;i<=m;i++) cin >> pos[i] >> xi[i];
    for(int i = 1;i<=n;i++) fir[i] = m+1, lst[i] = 0;
    for(int i = 1;i<=m;i++){
        if (fir[xi[i]] > m) fir[xi[i]] = i;
        if (lst[xi[i]]) nxt[lst[xi[i]]] = i;
        lst[xi[i]] = i;
    }
    for(int i = 1;i<=n;i++) if(lst[i]) nxt[lst[i]] = m+1;
    set<pair<int,int>> s;
    for(int i = 1;i<=n;i++) s.insert(pair<int, int>(fir[i], i));
    int sum = 0;
    for(int i = 1;i<=m;i++){
        int r = pos[i]-pos[i-1];
        while(!s.empty() && now[s.begin()->second] <= r){
            int k = s.begin()->second;
            sum += now[k];
            r -= now[k];
            now[k]=0;
            s.erase(s.begin());
        }
        if(s.empty() && r > 0) {
            cout << sum << endl;
            return ;
        }
        now[s.begin()->second] -= r;
        sum += r;
        now[xi[i]] = a[xi[i]];
        if(s.find(pair<int, int>(i, xi[i]))!= s.end()) s.erase(pair<int, int>(i, xi[i]));
        s.insert(pair<int, int>(nxt[i], xi[i]));
    }
    for(int i = 1;i<=n;i++) sum += now[i];
    cout<<sum<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) solve();
    return 0;
}