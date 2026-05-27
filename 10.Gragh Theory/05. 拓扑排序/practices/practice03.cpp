//https://www.luogu.com.cn/problem/P1038
/*
这里有个小坑,就是当一个神经元结点不活跃的时候,只是在下一层的计算上不算该结点的,注意入度照常计算
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,p;cin>>n>>p;
    vector<array<int,2> > arr(n+1);
    vector<vector<array<int,2> > > g(n+1);
    vector<int> in(n+1,0);
    for(int i = 1;i<=n;i++){
        int c,u;cin>>c>>u;
        arr[i] = {c,-u};
    }
    while(p--){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        in[v]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++) if(arr[i][0]) q.push(i);
    int cnt = 0;
    vector<vector<int> > ans(n+1);
    while(!q.empty()){
        int size = q.size();
        cnt++;
        for(int i = 0;i<size;i++){
            auto u = q.front();q.pop();
            ans[cnt].push_back(u);
            for(auto [v,w]:g[u]){
                in[v]--;
                if(arr[u][0] > 0) arr[v][1] += w*arr[u][0];
                if(in[v] == 0){
                    q.push(v);
                    arr[v][0] = arr[v][1];
                }
            }
        }
    }
    bool flg = false;
    for(int i:ans[cnt]){
        if(arr[i][0] > 0){
            cout<<i<<" "<<arr[i][0]<<endl;
            flg = true;
        }
    }
    if(!flg) cout<<"NULL";
    return 0;
}
