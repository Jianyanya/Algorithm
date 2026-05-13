//luogu,题目链接<https://www.luogu.com.cn/problem/P1535>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int N = 107;
const int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
ve arr(N,ve<char>(N));
ll n,m,time_maxam,r1,c1,r2,c2;
ve memt(N,ve(N,ve<ll>(20,-1)));
//这里的记忆化dfs的状态还要继承时间,那么dfs的状态为两个信息
//1.从当前的位置到终点的方案数,2.还有每种方案的消耗时间
//但是每种方案的时间都不同,记录每种不同时间的方案吗?
//所以把
ll dfs(int i,int j,int t){
    ll &res = memt[i][j][t];
    if(res!=-1) return res;
    //可以通过直接位置距离差距判断是否能到达
    if(abs(i-r2)+abs(j-c2)>time_maxam-t) return res = 0;
    //时间到头的时候直接判断
    if(t==time_maxam){
        if(i==r2&&j==c2) return res = 1;
        else return res = 0;
    }
    ll ans = 0;
    for(auto d:DIR){
        int x = i+d[0],y = j+d[1];
        if(x>0&&x<=n&&y>0&&y<=m&&arr[x][y]!='*'){
            ans += dfs(x,y,t+1);
        }
    }
    return res = ans;
}
void solve(){
    cin>>n>>m>>time_maxam;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>r1>>c1>>r2>>c2;
    cout<<dfs(r1,c1,0);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}