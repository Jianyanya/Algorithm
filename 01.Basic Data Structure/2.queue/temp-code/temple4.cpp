//最大总和-hdu-p1003,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=1003>
//这题是不定最大子序列和问题,比较简单,可以用贪心和动态规划解决
//不定就是不限定子数组的大小
//为了对比,还是做一下

//贪心
//hdu的编译器居然不支持bits/stdc++.h头文件
#include<iostream>
#include<vector>
using namespace std;
void slove1(){
    int n;cin>>n;
    for(int j = 1;j<=n;j++){
        int m;cin>>m;
        int sum = 0,start = 1,end = 1,p = 1;
        int mx = INT_MIN;
        for(int i = 1;i<=m;i++){
            int s;cin>>s;sum += s;
            if(sum>mx){
                mx = sum;
                start = p;
                end = i;
            }
            if(sum<0){
                sum = 0;
                p = i+1;
            }
        }
        cout<<"Case "<<j<<":"<<endl;
        cout<<mx<<" "<<start<<" "<<end<<" "<<endl;
        if(j!=n) cout<<endl;
    }
}
//动态规划
void slove2(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        int m;cin>>m;
        vector<int> dp(m+1);
        for(int i = 1;i<=m;i++) cin>>dp[i];
        int start = 1,end = 1,p = 1,mx = dp[1];
        for(int j = 2;j<=m;j++){
            if(dp[j-1]+dp[j]>=dp[j]){
                dp[j] = dp[j]+dp[j-1];
            }else p = j;
            if(dp[j]>mx){
                mx = dp[j];
                start = p;
                end = j;
            }
        }
        cout<<"Case "<<i<<":"<<endl;
        cout<<mx<<" "<<start<<" "<<end<<" "<<endl;
        if(i!=n) cout<<endl;
    }
}
int main(){
    //贪心
    slove1();
    //动态规划
    //slove2();
    return 0;
}