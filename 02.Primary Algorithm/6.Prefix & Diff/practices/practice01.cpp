//Subsequences Summing to Sevens S 题目链接<https://www.luogu.com.cn/problem/P3131>
/*
看到区间和就是前缀和了,但是问题在这个两个端点怎么找
这里需要用到一个小定理:若两个数相减(mod 7=0),那么这两个数 mod 7 的余数一定相同
所以现在就是找两个相同的端点且距离最远
怎么优化成O(n)
只能用空间换时间了,我们可以分别对数组进行遍历,记录每个数的第一个数和最后一个数,装入first和last两个数组中
最后再从0~6计算first和last最大差值打印就行
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int b[7],d[7];
int main(){
    cin>>n;
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        arr[i] = (arr[i]+arr[i-1])%7;
    }
    int ans= 0;
    for(int i = n;i>=0;i--)
        b[arr[i]] = i;
    for(int i = 0;i<=n;i++)
        d[arr[i]] = i;
    for(int i = 0;i<7;i++){
        ans = max(ans,d[i]-b[i]);
    }
    cout<<ans;
    return 0;
}