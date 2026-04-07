#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,X,Y,W;
    cin>>N>>X>>Y>>W;
    vector<pair<ll,ll>> a(N);
    for(int i = 0;i < N;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end(),[](auto &l, auto &r){
        return l.first < r.first;
    });
    ll ans = abs(X - a[0].first);
    ll cur = 0;
    ll pre = a[0].first;
    for(auto &[f, cnt] :a){
        ans += abs(f - pre);
        pre = f;
        ll dist = Y - f;
        ll k = cnt / W;
        ll r = cnt % W;
        ans += k * 2 * dist;
        cur += r;
        if(r==0&&cur==0){
            ans -= dist;
            pre = Y;
        }
        if(cur >= W){
            ans += 2 * dist;
            cur -= W;
            if(cur==0){
                 ans -= dist;
                 pre = Y;
            }
        }
    }
    if(cur > 0) ans += Y - pre;
    cout<<ans;
}