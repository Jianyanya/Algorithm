#include<bits/stdc++.h>
using namespace std;

bool f(int x){
    int res = 0;
    while(x>0){
        if(x & 1) res++;
        else res--;
        x >>= 1;
    }
    return res == 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int p;cin>>p;
        if(f(p)) ans++;
    }
    cout<<ans;
    return 0;
}