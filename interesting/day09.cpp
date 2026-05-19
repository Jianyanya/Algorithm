#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;

struct node{
    int pos;
    int val;
    int t;
};

int T;
void jianyanya(){
    int n;cin>>n;
    ve<int>a(n+1),b(n+1);
    fo(i,1,n) cin>>a[i];
    fo(i,1,n) cin>>b[i];
    ve<ve<node>> e(n+2);
    fo(i,1,n){
        if(a[i]==b[i]) e[a[i]].push_back({i,1,n+1});
        else{
            e[a[i]].push_back({i,0,n+1});
            e[b[i]].push_back({i,0,n+1});
        }
    }
    auto f = [&](ve<node>& v,int p){
        return lower_bound(v.begin(),v.end(),p,[](const node& x,int val){
            return x.pos<val;
        }) - v.begin();
    };
    for(int x=n;x>=1;x--){
        for(auto &cur:e[x]){
            if(!cur.val) continue;
            int idx = f(e[x+1],cur.pos+1);
            if(idx == e[x+1].size()) cur.t = n+1;
            else if(!e[x+1][idx].val) cur.t = e[x+1][idx].pos;
            else cur.t = e[x+1][idx].t;
        }
    }
    ll ans=0;
    fo(L,1,n){
        int res = n+1;
        int idx = f(e[1],L);
        if(idx != e[1].size()){
            if(!e[1][idx].val) res = e[1][idx].pos;
            else res = e[1][idx].t;
        }
        ans += res - L;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}