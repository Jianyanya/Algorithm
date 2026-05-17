//https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define endl '\n'
using ll = long long;
const ll INF = 4e18;
const int N = 1e4 + 10;

int n,m;
ll g[505][505], dis[505][505];
bool can[505][505];

//模板
/*
我看来更像动态规划
f[k][x][y]为允许经过1到k时的x到y的最短路
状态转移方程 : f[k][x][y] = min(f[k-1][x][y],f[k-1][x][k] + f[k-1][k][y]);
即以k为中转站,求x到k,k到y的最短路,即x到y的最短路,因为本质暴力,遍历了每种情况,所以是全源最短路
*/
void jianyanya(){
    int n,m,s;cin>>n>>m>>s;
    vector<vector<int> > dis(N,vector<int>(N));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j] = (i==j?0:INF);
        }
    }
    while(m--){
        int u,v,w;cin>>u>>v>>w;
        dis[u][v] = min(dis[u][v],w);
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<dis[s][i]<<" ";
    }
}
//1.给一个正权无向图，找一个最小权值和的环.
/*
以k为中转点,要形成环还需要求经过<k的点时x到y的最短路,所以在k之前跑一遍Floyd算法
*/
void jianyanya(){
    cin>>n>>m;
    fo(i,1,n){
        fo(j,1,n){
            g[i][j]=dis[i][j]=(i==j?0:INF);
        }
    }
    fo(i,1,m){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        if(w<g[u][v]){
            g[u][v]=g[v][u]=w;
            dis[u][v]=dis[v][u]=w;
        }
    }
    ll ans=INF;
    fo(k,1,n){
        fo(i,1,k-1){
            fo(j,i+1,k-1){
                if(dis[i][j]==INF||g[i][k]==INF||g[k][j]==INF) continue;
                ans=min(ans,dis[i][j]+g[i][k]+g[k][j]);
            }
        }
        fo(i,1,n){
            fo(j,1,n){
                if(dis[i][k]==INF||dis[k][j]==INF) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    if(ans==INF) cout<<"No solution."<<endl;
    else cout<<ans<<endl;
}

//2. 判断任意两点是否连通
/*
就是求图的闭包关系,a < b,b < c,那么a < c
*/
void jianyanya(){
    cin>>n;
    fo(i,1,n){
        fo(j,1,n){
            int x;
            cin>>x;
            can[i][j]=x;
        }
        can[i][i]=true;
    }
    fo(k,1,n){
        fo(i,1,n){
            fo(j,1,n){
                can[i][j]=can[i][j]||(can[i][k]&&can[k][j]);
            }
        }
    }
    fo(i,1,n){
        fo(j,1,n){
            cout<<can[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    while(T--) jianyanya();
}
