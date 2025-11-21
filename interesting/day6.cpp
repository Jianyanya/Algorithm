#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T;
void solve(){
    int n;cin>>n;
    ve<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int a = arr[0],b = arr[n-1];
    if(a==-1||b==-1){
        cout<<0<<endl;
        if(a==-1&&b==-1) a = 0,b = 0;
        else if(a==-1) a = b;
        else b = a;
    }
    else cout<<abs(arr[0]-arr[n-1])<<endl;
    cout<<a<<" ";
    for(int i = 1;i<n-1;i++){
        if(arr[i]!=-1) cout<<arr[i];
        else cout<<0;
        cout<<" ";
    }
    cout<<b<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}