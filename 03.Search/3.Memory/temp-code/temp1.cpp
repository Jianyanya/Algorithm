//luogu,题目链接<https://www.luogu.com.cn/problem/P1434>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int N = 105;
const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
ve arr(N,ve<int>(N)),memt(N,ve<int>(N,1));
int r,c,ans = 0;
int dfs(int i,int j){
    if(i<0||i>=r||j<0||j>=c) return 0;
    int &res = memt[i][j];
    if(res!=1) return res;
    for(auto d:DIR){
        int x = i+d[0],y = j+d[1];
        if(x>=0&&x<r&&y>=0&&y<c&&arr[i][j]>arr[x][y]){
            res = max(res,dfs(x,y)+1);
        }
    }
    return res;
}
void solve(){
    cin>>r>>c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            ans = max(ans,dfs(i,j));
        }
    }
    cout<<ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}