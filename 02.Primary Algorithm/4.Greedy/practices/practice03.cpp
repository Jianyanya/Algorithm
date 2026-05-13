//cf,题目链接<https://codeforces.com/problemset/problem/2145/C>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T,n;
sr str;
//0,1,2,3,2,3
//0,1,2,1,0,1,0
//0,-1,-2,-3,-4
//0,-1,-2,-1,0,-1,-2,-3,-2,-1,-2,-3,-2
//0,-1,-2,-1,-2,-3
//0,-1,-1,1,-1,-1
//我们要找到变化的状态,将问题转变为找到长度最短和为s的连续子数组
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>str;
        ve<int> arr(n+1,0);
        for(int i = 0;i<n;i++) 
            if(str[i]=='a') arr[i+1] = arr[i] - 1;
            else arr[i+1] = arr[i] + 1;
        int ans = INT_MAX;
        int sum = arr[n];
        //pre[r] - sum = pre[l]
        unordered_map<int,int> mp;
        mp[0] = 0;
        for(int i = 0;i<=n;i++){
            if(mp.count(arr[i]-sum)) ans = min(ans,i-mp[arr[i]-sum]);
            mp[arr[i]] = i;
        }
        if(ans==INT_MAX||ans==n) cout<<-1;
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}