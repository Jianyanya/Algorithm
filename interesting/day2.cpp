//https://sim.csp.thusaac.com/contest/38/problem/1
#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int ans = 1;
const int N = 101;
int arr[N][N] = {0};
void dfs(int x,int y,int i){
    if(x<1||x>n||y<1||y>n) return;
    if(i>m) return;
    if(arr[x][y]==0){
        ans++;
        arr[x][y]=1;
    }
    dfs(x-1,y+2,i+1);
    dfs(x-1,y-2,i+1);
    dfs(x+1,y+2,i+1);
    dfs(x+1,y-2,i+1);
    dfs(x-2,y+1,i+1);
    dfs(x-2,y-1,i+1);
    dfs(x+2,y+1,i+1);
    dfs(x+2,y-1,i+1);
}
int main(){
    cin>>n>>m>>a>>b;
    arr[a][b] = 1;
    dfs(a,b,0);
    cout<<ans;
    return 0;
}