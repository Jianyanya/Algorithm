//https://acm.hdu.edu.cn/showproblem.php?pid=2196
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<utility>//poj不能用
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int n,t = 0;
vector<vector<pair<int,ll> > > g;
vector<ll> dis,d1,d2,up;
void dfsd(int u,int fa){
        for(auto p:g[u]){
            int v = p.first;
            ll w = p.second;
            if(v == fa) continue;;
            dfsd(v,u);
            if(d1[v] + w > d1[u]){
                d2[u] = d1[u];
                d1[u] = d1[v] + w;
            }else if(d1[v] + w > d2[u]){
                d2[u] = d1[v] + w;
            }
        }
    }
void dfsu(int u,int fa){
        for(auto p:g[u]){
            int v = p.first;
            ll w = p.second;
            if(v == fa) continue;
            up[v] = up[u] + w;
            if(d1[v] + w != d1[u]) up[v] = max(up[v],d1[u] + w);//不在该子树节点中
            else up[v] = max(up[v],d2[u] + w);
            dfsu(v,u);
        }
    };
int main(){
    while(cin>>n){
        g.assign(n+1,{});
        d1.assign(n+1,0);
        d2.assign(n+1,0);
        up.assign(n+1,0);
        for(int i = 2;i<=n;i++){
            int v;
            ll w;cin>>v>>w;
            g[i].push_back({v,w});
            g[v].push_back({i,w});
        }
        dfsd(1,0);
        dfsu(1,0);
        for(int i = 1;i<=n;i++){
            cout<<max(d1[i],up[i])<<endl;
        }
    }
    return 0;
}