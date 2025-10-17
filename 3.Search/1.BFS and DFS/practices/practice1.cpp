//POJ-1321-棋盘问题,题目链接<http://bailian.openjudge.cn/practice/1321>
//八皇后的降级版,就是车的放置方案数
#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
int n,k;
char arr[9][9];
long long ans = 0;
int cl[9] = {0};
void dfs(int cur,int s){
    if(cur>k){
        if(s==k) ans++;
        return ;
    }
    //一排一排的搜
    for(int i = 0;i<n;i++){
        if(arr[cur][i]=='#'&&cl[i]==0){
            cl[i] = 1;//选了
            dfs(cur+1,s+1);
            cl[i] = 0;//回溯
        }
    }
    dfs(cur+1,s);
}
int main(){
    while(cin>>n>>k&&(n!=-1&&k!=-1)){
        memset(cl,0,sizeof(cl));
        int cnt  =0 ;
        ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='#') cnt++;
            }
        }
        if(cnt==k){
            cout<<1<<endl;
            continue;
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}