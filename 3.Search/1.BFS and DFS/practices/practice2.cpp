//洛谷-P5194-[USACO05DEC]Scales S,题目链接<https://www.luogu.com.cn/problem/P5194>
#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long ans = 0;
vector<long long> arr;
vector<long long> sum;
void dfs(int i,long long s){
    //直接返回
    if(s>k) return ;
    //判断剪枝
    if(s+sum[i]<=k){
        ans = max(ans,s+sum[i]);
        return;
    }
    ans = max(ans,s);
    for(int j = 0;j<i;j++){
        dfs(j,s+arr[j]);
    }
    return ;
}
//1 2 3 4 5
//0 1 3 6 10 15
int main(){
    cin>>n>>k;
    arr.resize(n);
    sum.resize(n+1);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        sum[i+1] = sum[i]+arr[i];
    }
    dfs(n,0);
    cout<<ans;
    return 0;
}