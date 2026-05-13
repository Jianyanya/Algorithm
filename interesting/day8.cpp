//https://atcoder.jp/contests/abc457/tasks/abc457_e
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
    int n,m;cin>>n>>m;
    ve<pair<int,int> > arr(m);
    fo(i,0,m-1){
        int l,r;cin>>l>>r;
        arr[i] = {l,r};
    }
    ranges::sort(arr);
    int q;cin>>q;
    while(q--){
        int s,t;cin>>s>>t;
        int l = INT_MAX-1,r = INT_MIN;
        bool flg = false;
        bool f = false;
        int cnt = 0;
        fo(i,0,m-1){
            if(arr[i].first == s && arr[i].second == t) f = true;
            if(arr[i].first >= s && arr[i].second <= t){
                cnt++;
                if(f && cnt >= 2){
                    flg = true;
                    break;
                }
            }
            if(arr[i].first > s && arr[i].second == t) l = min(l,arr[i].first);
            else if(arr[i].first == s && arr[i].second < t) r = max(r,arr[i].second);
            //cout<<arr[i].first<<" "<<arr[i].second<<"L:"<<l<<" "<<"R:"<<r<<endl;
            if(l - 1 <= r){
                flg = true;
                break;
            }
        }
        if(flg) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) jianyanya();
}