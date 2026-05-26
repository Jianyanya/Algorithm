//https://www.luogu.com.cn/problem/P3938
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOG = 31;

vector<ll> fib(61);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    fib[1] = fib[2] = 1;
    for(int i = 3;i<=60;i++) fib[i] = fib[i - 1] + fib[i - 2];
    while(n--){
        ll u,v;cin>>u>>v;
        while(u != v){
            if(u < v) swap(u,v);
            for(int i = 60;i>=1;i--){
                if(fib[i] < u){
                    u -= fib[i];
                    break;
                }
            }
        }
        cout<<u<<endl;
    }
    return 0;
}
