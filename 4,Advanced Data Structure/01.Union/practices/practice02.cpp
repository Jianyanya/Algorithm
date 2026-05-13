//https://atcoder.jp/contests/abc396/tasks/abc396_e
/*
异或就是单个二进制位上的关系，0就是相同，1就是不同,我发现,把$A_i$的所有二进制位拆开，就可以用带权并查集来维护异或关系。

设$a_i$为$Ax_i$中的每位上的数，$b_i$为$Ay_i$中每位上的数，$c_i$为$Z_i$上每位的数(只能为0或1)
这里并查集里的连通块就是$Ax_i$和$Ay_i$中0,1位的集合，而$Z_i$就是这两者集合的关系。
每个输入的约束`(x,y,z)`会把x和y所在的连通块合并(如果他们原本不在同一个块中)
即$(a_i - b_i)\bmod 2 = c_i$,(为0相同,1则不同)，其中就可以在并查集中构造计算$Ax_i$与$Ay_i$的每位的关系式。

统计答案时，同一连通块的元素通常分为两组,两组之间取值应当不同，只需要取其中较大的一组赋值为 0，另一组赋值为1即可保证总权值最小。
*/
#include <bits/stdc++.h>
using namespace std;
const int m = 2;
struct DSU{
    vector<int> fa,sz,dist;

    DSU(int n) :fa(n),sz(n,1),dist(n){
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        if(fa[x]==x) return x;
        int y = find(fa[x]);
        dist[x] ^= dist[fa[x]];
        return fa[x] = y;
    }

    bool merge(int from,int to,int d){
        find(from),find(to);
        d = d^dist[from]^dist[to];
        int x = fa[from],y = fa[to];
        if(x==y) return d==0;
        if(sz[x]<sz[y]){
            swap(x,y);
            d = (m - d)%m;
        }
        sz[x] += sz[y];
        fa[y] = x;
        dist[y] = d;
        return true;
    }
    
};

int main()
{
    int n,M;cin>>n>>M;
    DSU dsu((n+1)<<5);
    while(M--){
        int x,y,z;cin>>x>>y>>z;
        for(int i = 0;i<31;i++){
            if(!dsu.merge((x<<5)|i,(y<<5)|i,(z>>i)&1)){
                cout<<-1;
                return 0;
            }
        }
    }
    vector<int> cnt((n+1)<<5),arr(n+1);
    for(int i = 1;i<((n+1)<<5);i++){
        dsu.find(i);
        int y = dsu.fa[i];
        if(dsu.dist[i]) cnt[y]++;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<31;j++){
            int x = (i<<5)|j,y = dsu.fa[x];
            if((cnt[y]>dsu.sz[y]/2) ^ dsu.dist[x]) arr[i] |= 1<<j;
        }
    }
    for(int i = 0;i<n;i++) cout<<arr[i]<<" ";
  return 0;
}