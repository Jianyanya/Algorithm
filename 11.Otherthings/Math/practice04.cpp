//https://codeforces.com/contest/2224/problem/D
/*
我们要比较ai*bj和aj*bi的大小
所以按ai/aj 和bi/bj的大小对数组进行排序
最后计算这个数对的数量就行
*/
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
ll mypow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b & 1) ans = (ans * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return ans;
}
void jianyanya(){
    int n;cin>>n;
    ve<ll> a(n+1),b(n+1);
    fo(i,1,n) cin>>a[i];
    fo(i,1,n) cin>>b[i];
    ve<pair<ll,ll> > arr;
    fo(i,1,n-1){
        fo(j,i+1,n){
            arr.emplace_back(a[i],a[j]);
        }
    }
    auto cmp = [](auto &a, auto &b) {
        return 1LL * a.first * b.second < 1LL * b.first * a.second;
    };
    sort(arr.begin(),arr.end(),cmp);
    ve<pair<ll,ll> > temp;
    fo(i,1,n){
        fo(j,1,n){
            if(i != j) temp.emplace_back(b[i],b[j]);
        }
    }
    sort(temp.begin(),temp.end(),cmp);
    ll sum = 0;
    for(int j = 0,i = 0;i<(ll)arr.size();i++){
        while(j<(ll)temp.size()&& cmp(temp[j],arr[i])) j++;
        sum += j;
    }
    cout<<((sum % MOD) *mypow(n*(n - 1)%MOD,MOD - 2))%MOD<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}