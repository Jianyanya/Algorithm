//https://codeforces.com/contest/2226/problem/C
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
void jianyanya(){
    int n;cin>>n;
    ve<int> arr(n);
    fo(i,0,n-1) cin>>arr[i];
    auto check = [&](int m) -> bool {
        ve<ve<int> > cur(m);
        ve<int> ks(n);
        ve<int> res;
        fo(i,0,n-1){
            if(arr[i]==0) ks[i] = -1;
            else ks[i] = (arr[i] - 1)/2;
            if(arr[i]<m){
                if(!cur[arr[i]].empty()) res.push_back(ks[i]);
                else cur[arr[i]].push_back(ks[i]);
            }else if(arr[i]>=m&&ks[i]>=0) res.push_back(ks[i]);
        }
        ranges::sort(res);
        ve<int> h;
        fo(i,0,m-1){
            if(cur[i].empty()) h.push_back(i);
        }
        int id = 0;
        for(int x:h){
            while(id<res.size()&&res[id]<x) id++;
            if(id == res.size()) return false;
            id++;
        }
        return true;
    };
    int l = 0,r = n+1,ans = -1;
    while(l<=r){
        int mid = l + (r - l)/2;
        if(check(mid))  l = mid + 1,ans = mid;
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