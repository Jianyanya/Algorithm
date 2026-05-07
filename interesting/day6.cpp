//https://codeforces.com/contest/2224/problem/C
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
void jianyanya(){
    int n;cin>>n;
    sr a,b,s1 = "",s2 = "";cin>>a>>b;
    bool flg = true;
    fo(i,0,n-1){
        if(a[i] == b[i]) s1 += a[i],s2 += b[i];
        else{
            if(flg) s1 += '(',s2 += ')';
            else s1 += ')',s2 += '(';
            flg = !flg;
        }
    }
    int t1 = 0,t2 = 0;
    flg = true;
    fo(i,0,n-1){
        if(s1[i] == '(') t1++;
        else t1--;
        if(s2[i] == '(') t2++;
        else t2--;
        if(t1<0 || t2<0){
            flg = false;
            break;
        }
    }
    if(t1 != 0 || t2 != 0) flg = false;
    if(flg) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}