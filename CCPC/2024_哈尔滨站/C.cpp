#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = double long;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve(){
    int n;cin>>n;
    char b;
    ve<pair<char,int>> arr;
    char c,p;
    int num;
    for(int i = 0;i<n;i++){
        cin>>c>>num;
        if(i==0){
            b = c;
            p = c;
            arr.emplace_back('Z',num);
        }else{
            if(c=='E'){
                if(p=='N') arr.emplace_back('R',0);
                else arr.emplace_back('L',0);
                arr.emplace_back('Z',num);
            }else if(c=='N'){
                if(p=='E') arr.emplace_back('L',0);
                else arr.emplace_back('R',0);
                arr.emplace_back('Z',num);
            }else if(c=='W'){
                if(p=='N') arr.emplace_back('L',0);
                else arr.emplace_back('R',0);
                arr.emplace_back('Z',num);
            }else{
                if(p=='W') arr.emplace_back('L',0);
                else arr.emplace_back('R',0);
                arr.emplace_back('Z',num);
            }
            p = c;
        }
    }
    cout<<arr.size()<<" "<<b<<endl;
    for(auto [a,b]:arr){
        cout<<a<<" ";
        if(a=='Z') cout<<b;
        cout<<endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}