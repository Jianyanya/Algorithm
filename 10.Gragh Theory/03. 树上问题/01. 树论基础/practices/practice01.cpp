//https://www.luogu.com.cn/problem/P5018
/*
找子树中最大的对称二叉树,记住是子树,不是任意选
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1,right = -1,val;
};

int main(){
    int n;cin>>n;
    vector<node> arr(n+1);
    vector<int> cnt(n+1,0);
    for(int i = 1;i<=n;i++) cin>>arr[i].val;
    for(int i = 1;i<=n;i++) cin>>arr[i].left>>arr[i].right;
    auto dfs = [&](this auto&& dfs,int x,int y) -> bool {
        if(x == -1 && y == -1) return true;
        if(x == -1 || y == -1) return false;
        if(arr[x].val != arr[y].val) return false;
        return dfs(arr[x].left,arr[y].right) && dfs(arr[y].left,arr[x].right);
    };
    auto count = [&](this auto&& count,int x) -> int {
        if(x == -1) return 0;
        cnt[x] = count(arr[x].left) + count(arr[x].right) + 1;
        return cnt[x];
    };
    count(1);
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(dfs(i,i)) ans = max(ans,cnt[i]);
    }
    cout<<ans;
    return 0;
}