#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int lastans = 0;
    int n,x;cin>>n>>x;
    vector<vector<int> > g(n+1,vector<int>(n+1));
    vector<bool> arr(n+1,0);
    vector<pair<int,int> > qry;
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;cin>>k;
    for(int i = 0;i<k;i++){
        int p;cin>>p;
        arr[p] = true;
    }
    int m;cin>>m;
    for(int i = 0;i<m;i++){
        int s,t;cin>>s>>t;
        qry.push_back({s,t});
    }
    int q;cin>>q;
    while(q--){
        int op;cin>>op;
        if(op == 1){
            int u,v;cin>>u>>v;
            u = u^(x*lastans),v = v^(x*lastans);
            
        }else{

        }
    }
    return 0;
}