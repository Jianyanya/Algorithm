//洛谷<https://www.luogu.com.cn/problem/P4552>
#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
int main(){
    cin>>n;
    vector<ll> arr(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    ll q = 0,p = 0;
    for(int i = 1;i<n;i++){
        ll c = arr[i+1]-arr[i];
        if(c>0) q += c;
        else p -= c;
    }
    cout<<min(p,q)+abs(p-q)<<endl;
    cout<<abs(p-q)+1;
    return 0;
}