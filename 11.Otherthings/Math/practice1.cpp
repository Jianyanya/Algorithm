//cf,题目链接<https://codeforces.com/contest/1857/problem/F>
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
bool is_square(ll x,ll &s) {
    if (x < 0) return false;
    int d = x % 10;
    if(d != 0 && d != 1 && d != 4 && d != 5 && d != 6 && d != 9) return false;
    if (x % 4 == 2 || x % 4 == 3) return false;
    s = sqrt(x);
    while ((s + 1) * (s + 1) <= x) s++;
    while (s * s > x) s--;
    return s * s == x;
}
void solve(){
    int n;cin>>n;
    ve<int> arr(n);
    //极致哈希表优化:提前预订内存,查找一次hash,加优化哈希函数
    unordered_map<int,int,custom_hash> mp;
    mp.reserve(n * 2);
    mp.max_load_factor(0.7);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int Q;cin>>Q;
    while(Q--){
        ll x,y;cin>>x>>y;
        ll num = x*x - 4*y;
        ll t;
        if(!is_square(num,t)){
            cout<<0<<" ";
            continue;
        }
        ll a = (x - t)/2,b = (x+t)/2;
        ll cnt = 0;
        auto ita = mp.find(a);
        auto itb = mp.find(b);
        if(ita==mp.end() || itb==mp.end()){
            cout<<0<<" ";
            continue;
        }
        if(a==b){
            ll m = ita->second-1;
            cnt = m*(m+1)/2;
        }else cnt = 1LL*ita->second*itb->second;
        cout<<cnt<<" ";
    }
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}