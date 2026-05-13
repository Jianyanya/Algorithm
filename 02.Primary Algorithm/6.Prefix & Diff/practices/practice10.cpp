//https://atcoder.jp/contests/abc455/tasks/abc455_e
/*
前缀和+容斥定理
总数 - 不合法的子串
不合法 : a == b || b == c || a == c || a == b == c
统计一个区间内的字符出现次数,pre[r] - pre[l],则上述变成 prea[r] - prea[l] = preb[r] - preb[l] -> preb[l] - prea[l] = preb[r] - prea[r]
则就是求preb[i] - prea[i]相同的数量y,总共有y*(y-1)/2;
由于a==c&&a==b -> b==c.所以可以统计{preb[i] - prea[i],prec[i] - prea[i]}相同的数量
容斥定理 : 上面的a==b,b==c,a==c,已经统计过a==b==c的情况了,由容斥定理得AB + AC + BC - 2*(ABC),减去2倍的a==b==c的情况就行
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct PairHash{
    size_t operator()(const pair<int,int>&t)const{
        const auto &a = get<0>(t);
        const auto &b = get<1>(t);
        size_t seed = 2166136261U;
        seed = (seed^a)*16777619U;
        seed = (seed^b)*16777619U;
        return seed;
    }
};
int main() {
    ll n;cin>>n;
    string str;cin>>str;
    vector<int> prea(n+1,0),preb(n+1,0),prec(n+1,0);
    ll sum = n*(n+1)/2;
    for(int i = 1;i<=n;i++){
        prea[i] = prea[i-1] + (str[i-1]=='A');
        preb[i] = preb[i-1] + (str[i-1]=='B');
        prec[i] = prec[i-1] + (str[i-1]=='C');
    }
    unordered_map<int,int> mpa,mpb,mpc;
    unordered_map<pair<int,int>,int,PairHash> mpll;
    mpa[0] = mpb[0] = mpc[0] = mpll[{0,0}] = 1;
    ll res = 0;
    for(int i = 1;i<=n;i++){
        mpa[prea[i] - preb[i]]++;
        mpb[prea[i] - prec[i]]++;
        mpc[preb[i] - prec[i]]++;
        mpll[{prea[i] - preb[i],prea[i] - prec[i]}]++;
    }
    for(auto [a,b]:mpa) res += 1ll*b*(b-1)/2;
    for(auto [a,b]:mpb) res += 1ll*b*(b-1)/2;
    for(auto [a,b]:mpc) res += 1ll*b*(b-1)/2;
    for(auto [a,b]:mpll) res -= 1ll*b*(b-1);
    cout<<sum - res;
    return 0;
}