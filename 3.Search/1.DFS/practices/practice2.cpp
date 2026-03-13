//洛谷-P5194-[USACO05DEC]Scales S,题目链接<https://www.luogu.com.cn/problem/P5194>
/*
思路
我们似乎无法提前确定我们怎样放才能满足,必须枚举之后才知道大小,所以搜索所有可能,比较大小
但是这个题的限制比较明显,所以在搜索基础上剪枝,题目中给的砝码重量是单调的,可以从后面大的开始搜索(就像放石子,先放大的,再填小的)
二个剪枝:
- 使用前缀和记录每个数之前的总和,当前数加上前面总和满足条件的时候为最佳,直接记录答案
- 当前数大于k时,跳过
*/
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
    for(int j = i - 1;j>=0;j--){
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