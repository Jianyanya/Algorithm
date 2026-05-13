//洛谷-题目链接<https://www.luogu.com.cn/problem/P13787>
/*
基础的差分实现
前缀和差分
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int n,m,x1,y,x2,y2;
int arr[N][N];
int main(){
    cin>>n>>m;
    while(m--){
        cin>>x1>>y>>x2>>y2;
        arr[x1][y]++;
        arr[x1][y2+1]--;arr[x2+1][y]--;
        arr[x2+1][y2+1]++;
    }
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            arr[i][j] += arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            ans += (i+j)^arr[i][j];
        }
    }
    cout<<ans;
    return 0;
}