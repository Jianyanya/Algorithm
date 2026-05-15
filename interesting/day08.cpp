//https://atcoder.jp/contests/abc457/tasks/abc457_e
/*
m个布,覆盖范围为[l,r],q个询问,判断是否有两个及两个以上的布能覆盖s到t
考虑两种情况:
1.恰好有一个布正好覆盖到[l,r]
- 还有布能覆盖到[l,r],即[l,r]的布数量大于等于2
- 至少一个布能覆盖到[l+1,r]内
- 至少一个布能覆盖到[l,r-1]内
tip:为什么不直接判断s<l<r<t,因为要恰好覆盖,s和t的边界必定被覆盖,此外还要区分正好覆盖[l,r]的布
对于第一个,直接mp计数就行
对于第二个和第三个,记录每个l的最小r就行,同理,记录每个r的最大l
统计l >= i 的布料中最小的 r
2.没有布能正好覆盖到[l,r]
这时就要去拼接两个布了
记录l的所有r集合,记录r的所有l集合
判断时用二分法找到s记录的r集合中最接近且小于t的位置r
找到t记录的l集合中最接近且大于s的位置l
判断l是否小于r+1(l和r不相等的时候也可以完全覆盖),小于即yes,反之no
最优解为线段树,所以归为线段树
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
const int MX = 1e9;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    template<class T>
    static uint64_t hash_one(const T& x) {
        if constexpr (std::is_integral_v<T>) {
            return splitmix64(static_cast<uint64_t>(x));
        } else {
            return splitmix64(std::hash<T>{}(x));
        }
    }

    template<class T>
    static void hash_combine(uint64_t& seed, const T& x) {
        seed ^= hash_one(x) + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
    }

    template<class A, class B>
    size_t operator()(const std::pair<A, B>& p) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();

        uint64_t seed = FIXED_RANDOM;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);

        return splitmix64(seed);
    }

    template<class Tuple, size_t... I>
    static uint64_t hash_tuple_impl(const Tuple& tp, std::index_sequence<I...>) {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();

        uint64_t seed = FIXED_RANDOM;
        (hash_combine(seed, std::get<I>(tp)), ...);

        return splitmix64(seed);
    }

    template<class... Args>
    size_t operator()(const std::tuple<Args...>& tp) const {
        return hash_tuple_impl(tp, std::index_sequence_for<Args...>{});
    }

    template<class T>
    size_t operator()(const T& x) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(hash_one(x) + FIXED_RANDOM);
    }
};
void jianyanya(){
    int n,m;cin>>n>>m;
    unordered_map<pair<int,int>,int,CustomHash> mp;
    ve<ve<int> > ls(n+2),rs(n+2);
    ve<int> minlr(n+2,MX),maxrl(n+2,-MX);
    ve<int> l_r(n+2,MX),r_l(n+2,-MX);
    for(int i = 0;i<m;i++){
        int l,r;cin>>l>>r;
        mp[{l,r}]++;
        ls[l].push_back(r);
        rs[r].push_back(l);
        l_r[l] = min(l_r[l],r);
        r_l[r] = max(r_l[r],l);
    }
    for(int i = n;i>=1;i--){
        minlr[i] = min(minlr[i+1],l_r[i]);
    }
    for(int i = 1;i<=n;i++){
        maxrl[i] = max(maxrl[i-1],r_l[i]);
    }
    for(int i = 1;i<=n;i++){
        ranges::sort(ls[i]);
        ranges::sort(rs[i]);
    }
    int q;cin>>q;
    while(q--){
        int s,t;cin>>s>>t;
        bool flg = false;
        int cnt = mp[{s,t}];
        if(cnt > 0){
            if(cnt >= 2) flg = true;
            if(s + 1 <= t && minlr[s + 1] <= t) flg = true;
            if(s <= t - 1 && maxrl[t - 1] >= s) flg = true;
        }else{
            int l = MX,r = -1;
            auto it = ranges::upper_bound(ls[s],t);
            if(it != ls[s].begin()){
                it--;
                r = *it;
            }
            it =  ranges::lower_bound(rs[t],s);
            if(it != rs[t].end()) l = *it;
            if(l <= r + 1) flg = true;
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