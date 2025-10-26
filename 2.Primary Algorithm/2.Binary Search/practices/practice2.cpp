//cf,题目链接<https://codeforces.com/contest/1701/problem/C>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,a,b;
bool check(int mid,unordered_map<int,int> &mp){
    ll sum = 0;
    for(int i = 1;i<=a;i++){
        if(mid<=mp[i]) sum += mid;
        else sum += mp[i]+(mid-mp[i])/2;
        if(sum>=b) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>a>>b;
        unordered_map<int,int> mp;
        int p;
        for(int i = 0;i<b;i++){
            cin>>p;
            mp[p]++;
        }
        int left = 1,right = 2*b;
        while(left<right){
            int mid = left+(right-left)/2;
            if(check(mid,mp)) right = mid;
            else left = mid+1;
        }
        cout<<right<<endl;
    }
    return 0;
}