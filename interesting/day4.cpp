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
int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}