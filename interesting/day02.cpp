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
void jianyanya(){
    int n;cin>>n;
    ve<int> a(n),b(n),arr(n);
    int mx = 0;
    fo(i,0,n-1){
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    fo(i,0,n-1){
        cin>>b[i];
        mx = max(mx,b[i]);
    }
    auto check = [&](int x) -> bool {
        int cnt = 0,sum = 0;
        bool flg = false;
        fo(i,0,n-1){
            int top = max(a[i],b[i]);
            int bt = min(a[i],b[i]);
            if(bt >= x){
                cnt++;
                flg = false;
            }
            else if(top < x){
                if(!flg) sum++;
                flg = true;
            }
        }
        return cnt > sum;
    };
    int l = 0,r = mx,ans = 0;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(check(mid)) l = mid + 1,ans = mid;
        else r = mid - 1;
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}