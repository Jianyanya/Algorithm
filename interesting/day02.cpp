//牛客,题目链接<https://ac.nowcoder.com/acm/contest/123509/I>
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
void solve(){
    int n;cin>>n;
    unordered_map<pair<int,int>,int,PairHash> mp;
    fo(i,1,n){
        sr str;cin>>str;
        int a = 0,b = 0;
        for(char c:str){
            if(c=='0') a++;
            else b++;
        }
        mp[{a,b}]++;
    }
    int ans = 0;
    ve<pair<int,int>> arr;
    for(auto &[a,b]:mp) arr.push_back(a);
    set<pair<int,int>> st;
    fo(i,0,arr.size()-1){
        fo(j,i,arr.size()-1){
            auto &A = arr[i];
            auto &B = arr[j];
            auto target = make_pair(A.first+B.first,A.second+B.second);
            if(mp.count(target)&&!st.count(target)){
                bool falge = false;
                if(i==j){
                    if(A==target) falge = (mp[A]>=3);
                    else falge = (mp[A]>=2);
                }else{
                    if(A==target||B==target) falge = (A==target?mp[A]>=2:mp[A]>=1)&&(B==target?mp[B]>=2:mp[B]>=1);
                    else falge = true;
                }
                if(falge){
                    ans += mp[target];
                    st.insert(target);
                } 
            }
        }
    }
    cout<<ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T=1;
    while(T--) solve();
}