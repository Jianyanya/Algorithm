#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = long double;
const int MOD=998244353;
const int MX = 1e9;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;

void jianyanya(){
    int n;
    sr s;
    cin>>s;
    n = s.size();
    ll ans=1;
    ll r=0,b=0,cur=0;
    for(char c:s){
        if(c=='W'){
            ans=max(ans,cur);
            r=b=cur=0;
        }else if(c=='R'){
            if(b>0){
                b--;
                r++;
            }else{
                r++;
                cur++;
            }
        }else{
            if(r>0){
                r--;
                b++;
            }else{
                b++;
                cur++;
            }
        }
    }
    ans=max(ans,cur);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}
