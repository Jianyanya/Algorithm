//除了这个不进位加法之外,还要用线段树维护区间的和
//只会这个不进位加法只能得50分,剩下的分估计不仅要会线段树,还要在线段树上进行差分优化
//还有一个点就是题目给的这个k是奇数,不然还要额外维护最低位取值分布
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
ll cnt = 65;
vector<vector<ll> >ks;
vector<ll> kpow;
ll calc(ll a,ll b){
    vector<int> fa(cnt+1,0);
    vector<int> fb(cnt+1,0);
    for(int j = cnt;j>=0;j--){
        if(a >= kpow[j]){
            fa[j] = a/kpow[j];
            a %= kpow[j];
        }
        if(b >= kpow[j]){
            fb[j] = b/kpow[j];
            b %= kpow[j];
        }
    }
    ll res = 0;
    for(int i = 0;i<=cnt;i++){
        res += ((fa[i] + fb[i])%k)*kpow[i];
    }
    return res;
}

ll f(ll x) {
    if (x <= 0) return 0;
    ll res = 0;
    ll pow = 1;
    while (pow <= x) {
        ll total = x + 1;
        ll full = total / (pow * k);
        ll rem = total % (pow * k);
        ll d = rem / pow;
        ll r = rem % pow;
        ll sum_bits = full * pow * (k * (k - 1) / 2)
                           + pow * (d * (d - 1) / 2)
                           + d * r;
        ll digit = sum_bits % k;
        res += digit * pow;
        if (pow > x / k) break;
        pow *= k;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    vector<ll> arr(n+1);
    ll mx = 0;
    for(int i = 1;i<=n;i++) cin>>arr[i];
    ks.assign(n+1,vector<ll>(cnt+1,0));
    mx = 1;
    cnt = 0;
    kpow.assign(65, 0);
    kpow[0] = 1;
    while (kpow[cnt] <= LLONG_MAX / k) {
        kpow[cnt + 1] = kpow[cnt] * k;
        cnt++;
    }
    for(int i = 1;i<=n;i++){
        ll x = arr[i];
        for(int j = cnt;j>=0;j--){
            if(x >= kpow[j]){
                ks[i][j] = x/kpow[j];
                x %= kpow[j];
            }
        }
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 0;j<=cnt;j++){
    //         cout<<ks[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(m--){
        int t;cin>>t;
        if(t == 1){
            ll l,r,v;cin>>l>>r>>v;
            vector<int> vs(cnt+1,0);
            for(int i = cnt;i>=0;i--){
                if(v >= kpow[i]){
                    vs[i] = v/kpow[i];
                    v %= kpow[i];
                }
            }
            for(int i = l;i<=r;i++){
                for(int j = 0;j<=cnt;j++){
                    ks[i][j] = (ks[i][j] + vs[j])%k;
                }
            }
        }else{
            int l,r;cin>>l>>r;
            for(int i = l;i<=r;i++){
                ll res = 0;
                for(int j = 0;j<=cnt;j++){
                    res += (ks[i][j]%k)*kpow[j];
                }
                arr[i] = f(res);
            }
            ll ans = arr[l];
            for(int i = l+1;i<=r;i++){
                ans = calc(ans,arr[i]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
