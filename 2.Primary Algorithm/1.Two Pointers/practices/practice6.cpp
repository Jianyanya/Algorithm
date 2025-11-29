#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int N = 2e5+5;
int T;
int n,k,l,r;
ve<int> arr(N);
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
ll f(int m){
    ll ans = 0;
    unordered_map<int,int,custom_hash> mp;
    for(int right = 0,left = 0;right<n;right++){
        mp[arr[right]]++;
        while(left<=right&&mp.size()>m){
            mp[arr[left]]--;
            if(mp[arr[left]]==0) mp.erase(arr[left]);
            left++;
        }
        ans += max(min(right-left+1,r)-l+1,0);
    }
    return ans;
}
void solve(){
    cin>>n>>k>>l>>r;
    for(int i = 0;i<n;i++) cin>>arr[i];
    cout<<f(k)<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}