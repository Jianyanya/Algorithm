#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = long double;
const int MOD=998244353;
const int MX = 1e9;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void g(ll x,ve<pair<ll,ll>>& path){
    ll step = 0;
    while(x > 2){
        path.push_back({x,step});
        if(x&1) x++;
        else x /= 2;
        step++;
    }
    path.push_back({x,step});
    path.push_back({3-x,step+1});
}
void jianyanya(){
    int n;cin>>n;
    ll x;cin>>x;
    ve<pair<ll,ll>> arr;
    g(x,arr);
    ranges::sort(arr);
    int m = arr.size();
    ve<ll> val(m),sum(m);
    fo(i,0,m-1){
        val[i] = arr[i].first;
        sum[i] = arr[i].second;
    }
    ve<int> ok(m,1),vis(m,0);
    int t = 0;
    auto f = [&](ll y,ll step){
        int id = ranges::lower_bound(val,y) - val.begin();
        if(id < m && val[id] == y && ok[id] && vis[id] != t){
            vis[id] = t;
            sum[id] += step;
        }
    };
    fo(i,2,n){
        cin>>x;
        t++;
        ll step = 0;
        while(x > 2){
            f(x,step);
            if(x&1) x++;
            else x /= 2;
            step++;
        }
        f(x,step);
        f(3 - x,step + 1);
        fo(j,0,m-1){
            if(ok[j] && vis[j] != t) ok[j] = 0;
        }
    }
    ll ans = LLONG_MAX;
    fo(i,0,m-1){
        if(ok[i]) ans = min(ans,sum[i]);
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}