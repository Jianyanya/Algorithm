//自定义的题目
/*
给出一系列经验包,每个经验包的价格不同,初始你有S的钱,每个经验包的第一次购买的经验值和后来购买时不同,求怎么购买使得到的经验最多
*/
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve(){
    int n,target;cin>>n>>target;
    ve<int> arr(n),e(n),b(n);
    for(int i = 0;i<n;i++) cin>>arr[i]>>e[i]>>b[i];
    ve<ll> memt(n+1,-1);
    auto dfs = [&](this auto&& dfs,ll x) -> ll {
        if(x<=0) return 0;
        ll &res = memt[x];
        if(res!=-1) return res;
        res = INF;
        for(int i = 0;i<n;i++){
            //为什么这样,dfs的状态为当前选的经验包,每次访问后不会再回头访问,能保证唯一
            //选了第一次后,有两种选法:1,不再选该经验包了,继续后面的选择.2,继续选择当前的经验包
            //第一种选法,选第一次的
            res = min(res,dfs(x-(e[i]+b[i])+arr[i]));
            //第二种选法,已经选过第一次了
            res = min(res,dfs(x-e[i])+arr[i]);
        }
        return res;
    };
    ll ans = dfs(target);
    if(ans>=INF/2) cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}