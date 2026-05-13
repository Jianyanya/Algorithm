//cf,题目链接<https://codeforces.com/problemset/problem/2140/C>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;  
using db = double;
ll T,n,v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        ll ans =  0;
        ll l = INT_MAX,r = INT_MAX,mx = n-2+n%2;
        for(ll i = 0;i<n;i++){
            cin>>v;
            if(i%2>0){
                ans -= v;
                mx = max(mx,i+2*v-r);
                l = min(l,i-2*v);
            }else{
                ans += v;
                mx = max(mx,i-2*v-l);
                r = min(i+2*v,r);
            }
        }
        cout<<ans+mx<<endl;
    }
    return 0;
}