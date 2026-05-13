//cf,题目链接<https://codeforces.com/problemset/problem/493/C>
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
int n,m;
void solve(){
    cin>>n;
    ve<pair<int,int>> arr;
    fo(i,1,n){
        int p;cin>>p;
        arr.emplace_back(p,0);
    }
    cin>>m;
    fo(i,1,m){
        int p;cin>>p;
        arr.emplace_back(p,1);
    }
    ranges::sort(arr);
    int a = 3*n,b = 3*m;
    int ansa = a,ansb = b;
    int diff = a-b;
    fo(i,0,arr.size()-1){
        int d = arr[i].second;
        if(d) b--;
        else a--;
        bool flge = false;
        if(i==arr.size()-1||arr[i].first!=arr[i+1].first) flge = true;
        if(flge){
            int newdif = a - b;
            if(newdif>diff) ansa = a,ansb = b,diff = newdif;
        }
    }
    cout<<ansa<<':'<<ansb;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}