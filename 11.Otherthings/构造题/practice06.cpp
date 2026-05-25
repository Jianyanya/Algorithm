//https://codeforces.com/contest/2229/problem/C2
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
    ll sum = 0;
    ve<int> arr(n+1);
    fo(i,1,n) cin>>arr[i];
    ll mx = 0,id = -1,pre = 0;
    fo(i,1,n){
        if(arr[i] > 0){
            ll t = pre - arr[i];
            if(t > mx){
                mx = t;
                id = i;
            }
        }else pre += -arr[i];
    }
    if(id == -1){
        cout<<0<<endl;
        cout<<endl;
        return;
    }
    ve<bool> nd(n+1,false);
    nd[id] = true;
    fo(i,1,id-1) if(arr[i] < 0) nd[i] = true;
    ve<int> res;
    fo(i,1,id) if(nd[i] ^ nd[i + 1]) res.push_back(i);
    // for(int x:res) cout<<x<<" ";
    // cout<<endl;
    list<int> ans;
    ans.push_back(res.back());
    //1 3 4 5 6 7
    //+ - + - + +
    for(int i = (int)res.size()-2;i>=0;i--){
        int d = res[i];
        if(arr[d] > 0){
            ans.push_front(d);
        }else{
            ans.insert(next(ans.begin()),d);
        }
    }
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}