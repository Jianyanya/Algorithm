//poj-2251-地下城主,题目链接<http://bailian.openjudge.cn/practice/2251>
/*
不难,就是6个方向的bfs
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;
const int DIR[6][3] = {{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,-1},{0,0,1}};
int l,r,c;
int sl,sr,sc;
char arr[31][31][31];
bool visited[31][31][31];
int main() {
    while(cin>>l>>r>>c&&(l!=0&&r!=0&&c!=0)){
        int time = INT_MAX;
        memset(visited, false, sizeof(visited));
        int L = l;
        while(l--){
            for(int i = 0;i<r;i++){
                for(int j = 0;j<c;j++){
                    cin>>arr[i][j][l];
                    if(arr[i][j][l]=='S') sl = l,sr = i,sc = j;
                }
            }
        }
        queue<vector<int>> q;
        q.push({sr,sc,sl});
        visited[sr][sc][sl] = true;
        int m = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                auto arry = q.front();q.pop();
                int a = arry[0],b = arry[1],o = arry[2];
                if(arr[a][b][o]=='E'){
                    time = m;
                    goto break_val;
                }
                for(auto &d:DIR){
                    int x = a+d[0],y = b+d[1],z = o+d[2];
                    if(x>=0&&x<r&&y>=0&&y<c&&z>=0&&z<L&&!visited[x][y][z]&&(arr[x][y][z]=='.'||arr[x][y][z]=='E')){
                        visited[x][y][z] = true;
                        q.push({x,y,z});
                    }
                }
            }
            m++;
        }
        break_val:;
        if(time==INT_MAX) printf("Trapped!");
        else printf("Escaped in %d minute(s).",time);
        printf("\n");
    }
    return 0;
}