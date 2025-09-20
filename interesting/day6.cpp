#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n+1);
    vector<int> bt(n);
    for(int i = 0;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        cin>>bt[i];
    }
    //直接进行模拟比较简单,但是估计只能得80分
    for(int i = 0;i<n;i++){
        int x = 0;
        int ans =0 ;
        for(int j=  0;j<=n;j++){
            if(arr[j]>x) ans += arr[j]-x;
            else x -= arr[j];
            if(j!=i&&j<n) x += bt[j];
        }
        cout<<ans<<" ";
    }
    return 0;
}