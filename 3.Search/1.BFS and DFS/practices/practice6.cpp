//lougu-棋盘染色问题,题目链接<https://www.luogu.com.cn/problem/P1162>
/*
唯一的问题就是1内的0和1外的0不好区分
学京爷的溜边吃法,从边上开始dfs搜索所有连续的0,并标记
最后就直接是岛屿问题,搜索1中的0再bfs涂成一样的2就行
*/
#include<bits/stdc++.h>
using namespace std;
int n;
const int DIR[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector arr(31,vector<int>(31));
vector memt(31,vector<int>(31,0));
void dfs(int i,int j){
    if(i<0||i>=n||j<0||j>=n) return ;
    if(arr[i][j]!=0) return ;
    arr[i][j] = 3;
    for(auto &d:DIR){
        int x = d[0]+i,y = j+d[1];
        if(i>=0&&i<n&&j>=0&&j<n) dfs(x,y);
    }
}
void bfs(int i,int j){
    if(i<0||i>=n||j<0||j>=n) return ;
    if(arr[i][j]!=0) return ;
    arr[i][j] = 2;
    for(auto &d:DIR){
        int x = d[0]+i,y = j+d[1];
        if(i>=0&&i<n&&j>=0&&j<n) bfs(x,y);
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i][0]==0) dfs(i,0);
        if(arr[i][n-1]==0) dfs(i,n-1);
        if(arr[0][i]==0) dfs(0,i);
        if(arr[n-1][i]==0) dfs(n-1,i);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j]==0){
                bfs(i,j);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j]==3) cout<<0<<" "; 
            else cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}