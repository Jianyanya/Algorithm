//洛谷-八皇后,题目链接<https://www.luogu.com.cn/problem/P1219>
#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
int cl[13] = {0};
vector<int> dui1(30,0);
vector<int> dui2(30,0);
vector<vector<int>> arr;
vector<int> memt(13,-1);
auto dfs(int s){
    if(s==n){
        arr.push_back(memt);
        ans++;
        return;
    }
    for(int i = 0;i<n;i++){
        if(!cl[i]&&!dui1[s-i+n-1]&&!dui2[s+i]){
            cl[i] = dui1[s-i+n-1] = dui2[s+i] = 1;
            memt[s] = i+1;
            dfs(s+1);
            memt[s] = -1;
            cl[i] = dui1[s-i+n-1] = dui2[s+i] = 0;
        }
    }
};
int main(){
    cin>>n;
    dfs(0);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j];
            if(j!=n-1) cout<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}