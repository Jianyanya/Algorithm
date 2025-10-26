//poj-3279-奶牛踩格子,题目链接<http://poj.org/problem?id=3279>
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<climits>
using namespace std;
#define MEME(x,y) memset(x,y,sizeof(x))
int n,m;
int brr[16][16];//原模板
int arr[16][16];//动态模板
int ans[16][16];
int temp[16][16];//动态模板
void press(int i,int j){
    if(i-1>=0) arr[i-1][j] ^= 1;
    arr[i][j] ^= 1;
    if(i+1<n) arr[i+1][j] ^= 1;
    if(j-1>=0) arr[i][j-1] ^= 1;
    if(j+1<m) arr[i][j+1] ^= 1;
}
int slove(){
    int o = 0;
    //先根据temp第一行来改变arr
    for(int i = 0;i<m;i++){
        if(temp[0][i]){
            press(0,i);
            o++;
        }
    }
    //剩下的
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i-1][j]){
                press(i,j);
                temp[i][j] = 1;
                o++;
            }
        }
    }
    //检查最后一行
    for(int i = 0;i<m;i++){
        if(arr[n-1][i]) return INT_MAX;
    }
    return o;
}
int main() {
    cin>>n>>m;
    int count = INT_MAX;
    //输入
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>brr[i][j];
        }
    }
    //开始遍历每种第一行的选择情况
    for(int k = 0;k<(1<<m);k++){
        //重置
        MEME(temp,0);
        //搞
        for(int j = 0; j < m; j++) {
            if(k & (1 << j)) {
                temp[0][j] = 1;
            }
        }
        //重置
        memcpy(arr,brr,sizeof(brr));
        //计数
        int cnt = slove();
        //比较答案
        if(cnt<count){
            count = cnt;
            memcpy(ans,temp,sizeof(temp));
        }
    }
    if(count==INT_MAX) cout<<"IMPOSSIBLE";
    else {
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<ans[i][j];
                if(j!=m-1) cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}