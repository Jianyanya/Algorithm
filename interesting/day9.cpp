#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
void solve(){
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++){
        bool flage = false;
        for(int j = 1;j<=m;j++){
            if(j%2==0){
                if(i==1){
                    if(flage){
                        cout<<"x";
                        flage = !flage;
                    }else{
                        cout<<".";
                        flage = !flage;
                    }
                }
                else if(i==n){
                    if(!flage){
                        cout<<"x";
                        flage = !flage;
                    }else{
                        cout<<".";
                        flage = !flage;
                    }
                }else cout<<".";
            }
            else cout<<"x";
        }
        cout<<endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}