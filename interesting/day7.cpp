#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<bool> vis(20,false);
void dfs(){
    if(ans.size()==6){
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i<=6;i++){
        if(vis[i]) continue;
        vis[i] = true;
        ans.push_back(i);
        dfs();
        ans.pop_back();
        vis[i] = false;
    }
}
int main(){
    dfs();
    return 0;
}