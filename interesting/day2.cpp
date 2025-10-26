//cf题目链接<https://codeforces.com/problemset/problem/2064/C>
// 0, 3, 4, 8, 8,8,8
//15,15,15,15,14,9,0
//0 3  -1  4 -1 5 -9     3+4+5+9 = 21
//正数则最大前缀和,负数则最大后缀和
//正数从左边开始选,负数从右边开始选
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n;
    while(n--){
        cin>>m;
        vector<long long> arr(m+1);
        vector<long long> pre(m+1);
        vector<long long> suf(m+1);
        for(int i = 1;i<=m;i++){
            cin>>arr[i];
            pre[i] = pre[i-1]+(arr[i]>=0?arr[i]:0);
        }
        for(int i = m-1;i>=0;i--) suf[i] = suf[i+1]+(arr[i+1]<0?-arr[i+1]:0);
        long long ans = 0;
        for(int i = 0;i<=m;i++){
            ans = max(pre[i]+suf[i],ans);
        }
        cout<<ans;
        cout<<endl;
    }
    return 0;
}