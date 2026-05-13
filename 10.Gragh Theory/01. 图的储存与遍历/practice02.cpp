//https://www.luogu.com.cn/problem/P2921
/*此题依旧是判断是否有环
但是有多环情况,且要输出每个点所在环长度和最长有效路径
由于我只会三色标记法,所以我只能在此基础上实现了
原理不变,用三色标记法去得到环,同时记录节点答案
重点在回溯的时候,我们利用回溯,去对环上的点进行赋值,回溯一定会回到成环的节点,所以当再次遇到环节点的时候就重置
对于不在环内的点,我们直接ans[now] = ans[nxt] + 1就行了,对于2(已经统计过了)也是这样
实现细节:
vis只有三色 0/1/2
利用dfs返回整数,大于0则回溯环,小于0则非环元素,由于提前记录了前一个节点的值,所以可以直接+1
在每个return 前都要记得对该位置标记2
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int > arr(n+1);
    vector<int> vis(n+1,0),t(n+1,0),ans(n+1,0);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    int nub = 0;
    auto dfs = [&](this auto&& dfs,int id,int cur) -> int {
        int nxt = arr[id];
        vis[id] = 1;
        t[id] = cur;
        if(vis[nxt] == 1){
            int cnt = cur - t[nxt] + 1;
            ans[id] = cnt;
            nub = nxt;
            vis[id] = 2;
            if(id == nub){
                nub = 0;
                return 0;
            }
            return cnt;
        }
        if(vis[nxt] == 2){
            ans[id] = ans[nxt] + 1;
            vis[id] = 2;
            return 0;
        }
        int res = dfs(nxt,cur+1);
        if(res > 0){
            ans[id] = res;
            if(id == nub){
                nub = 0;
                vis[id] = 2;
                return 0;
            }
            vis[id] = 2;
            return res;
        }else{
            ans[id] = ans[nxt] + 1;
            vis[id] = 2;
            return 0;
        }
    };
    for(int i = 1;i<=n;i++){
        //t.assign(n+1,0);
        if(vis[i] == 0) dfs(i,1);
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    //cout<<cnt;
    return 0;
}