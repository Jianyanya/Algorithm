//洛谷,题目链接<https://www.luogu.com.cn/problem/P14665>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    ve<int> arr(n);
    int mn = INT_MAX, mx = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        mn = min(arr[i],mn);
        mx = max(arr[i],mx);
    }
    auto check = [&](int mid)->bool {
        vector<ll> cd;
        for(ll x :arr){
            cd.push_back(x);
            cd.push_back(x-mid);
        }
        ranges::sort(cd);
        cd.erase(unique(cd.begin(),cd.end()),cd.end());
        for(ll L :cd){
            ll R = L + mid;
            vector<ll> nd(n);
            for(int i = 0;i < n;i++){
                if(arr[i]<L) nd[i] = L - arr[i];
                else if(arr[i] > R) nd[i] = R - arr[i];
                else nd[i] = 0;
            }
            ll t = 0;
            ll temp = 0;
            for(int i = 0;i < n;i++){
                if(nd[i] == 0){
                    t += temp;
                    temp = 0;
                    continue;
                }
                if (i > 0 && (nd[i] > 0) == (nd[i - 1] > 0)) {
                    temp = max(temp, abs(nd[i]));
                } else {
                    t += temp;
                    temp = abs(nd[i]);
                }
            }
            t += temp;
            if(t<=m) return true;
        }
        return false;
    };
    int l = 0, r = mx - mn;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}