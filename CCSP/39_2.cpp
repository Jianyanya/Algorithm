#include<bits/stdc++.h>
using namespace std;

int arr[5][9] = {
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,1,0,1},
    {1,0,0,1,1,1,1,1,0},
    {1,0,0,0,0,1,1,0,0},
    {1,1,1,1,1,1,1,0,0},
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<vector<int> > g(n+1,vector<int>(n+1));
    int mx = 0,mn = INT_MAX;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>g[i][j];
            mx = max(g[i][j],mx);
            mn = min(g[i][j],mn);
        }
    }
    vector<long long> vis(max(mx,m) + 1);
    for(int i = 0;i<=n-4;i++){
        for(int j = 0;j<=n-8;j++){
            int mx1 = 0,mn1 = INT_MAX;
            for(int x = i;x<=i+4;x++){
                for(int y = j;y<=j+8;y++){
                    //cout<<g[x][y]<<" ";
                    //cout<<arr[x-i][y-j]<<" ";
                    if(arr[x-i][y-j]){
                        mn1 = min(g[x][y],mn1);
                    }else{
                        mx1 = max(g[x][y],mx1);
                    }
                }
            }
            if(mx1 < mn1){
                vis[mx1+1]++;
                vis[mn1 + 1]--;
            }
        }
    }
    for(int i = max(1,mn);i<=min(mx,m);i++){
        vis[i] += vis[i - 1];
        if(vis[i] > 0) cout<<i<<endl;
    }
    return 0;
}
