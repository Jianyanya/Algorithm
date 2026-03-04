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
int n,k,l,r;
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
void solve(){
    cin>>n>>k>>l>>r;
    ve<int> arr(n);
    fo(i,0,n-1) cin>>arr[i];
    auto f = [&](int m) -> ll {
        if(m<1) return 0;
        unordered_map<int,int,custom_hash> mp;
        ll left = 0,ans = 0,cnt = 0;
        for(int right = 0;right<n;right++){
            mp[arr[right]]++;
            if(mp[arr[right]]==1) cnt++;
            while(cnt>m){
                mp[arr[left]]--;
                if(mp[arr[left]]==0) cnt--;
                left++;
            }
            int len = right - left + 1;
            ans += max(min(len,r)-l+1,0);
        }
        return ans;
    };
    cout<<f(k) - f(k-1)<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}