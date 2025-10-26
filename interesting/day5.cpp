//cf题目链接<https://codeforces.com/problemset/problem/1931/D>
#include<bits/stdc++.h>
using namespace std;
int T,n,x,y;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        vector<int> arr(n);
        map<pair<int,int>,int> mp;
        long long ans = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            ans += mp[pair{(x-arr[i]%x)%x,arr[i]%y}];
            mp[pair{arr[i]%x,arr[i]%y}]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}