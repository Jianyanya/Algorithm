//https://www.luogu.com.cn/problem/B3644
//拓扑排序的经典应用模板
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> indeg,ord;

bool topo(){
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        ord.push_back(u);
        for(int v:g[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    return (int)ord.size() == n;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    g.assign(n+1,{});
    indeg.assign(n+1,0);
    for(int i = 1;i<=n;i++){
        int v;
        while(cin>>v && v!= 0){
            g[i].push_back(v);
            indeg[v]++;
        }
    }
    if(!topo()){
        cout<<"has cycle"<<endl;
    }else{
        for(int x:ord){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}