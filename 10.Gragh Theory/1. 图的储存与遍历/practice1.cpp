//https://www.luogu.com.cn/problem/P2661
/*
经典判断有向图是否有环
此题还要求最小环
使用三色标记法,本质就是dfs+时间戳
0为未访问过的,1为已经访问过但可能成环的,2为已经访问过没有其他情况
怎么记录环长呢,在从入口进入到环,先计数,将遍历过的长度存入该节点的下一个节点中
在遍历到环,即再次遇到1时,用当前长度减去该节点储存的长度(环外链表长度)就是环长
对于每个访问过的点,我们进行回溯的时候标记为2,此后不会再进行访问
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int > arr(n+1);
    vector<int> vis(n+1,0),t(n+1,0);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    int cnt = INT_MAX;
    auto dfs = [&](this auto&& dfs,int id,int cur) -> void {
        if(vis[id] == 1){
            cnt = min(cur - t[id],cnt);
            return ;
        }
        if(vis[id] == 2) return ;
        vis[id] = 1;
        t[id] = cur;
        dfs(arr[id],cur+1);
        vis[id] = 2;
    };
    for(int i = 1;i<=n;i++){
        //t.assign(n+1,0);
        if(vis[i] == 0) dfs(i,0);
    }
    cout<<cnt;
    return 0;
}