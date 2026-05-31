#include<bits/stdc++.h>
using namespace std;

const int DIR[8][2] = {
    {1,0},{-1,0},{0,1},{0,-1},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H,W;cin>>H>>W;
    vector<string> s(H);
    for(int i = 0;i<H;i++) cin>>s[i];
    vector<vector<int> > dis(H,vector<int>(W,-1));
    queue<pair<int,int> > q;
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            bool ok = false;
            for(auto [dx,dy]:DIR){
                int x = i + dx,y = j + dy;
                if(x < 0 || x >= H || y < 0 || y >= W) continue;
                if(s[x][y] != s[i][j]) ok = true;
            }
            if(ok){
                dis[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    if(q.empty()){
        for(int i = 0;i<H;i++){
            for(int j = 0;j<W;j++) cout<<'.';
            cout<<endl;
        }
        return 0;
    }
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy]:DIR){
            int nx = x + dx,ny = y + dy;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx,ny});
        }
    }
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            char c = s[i][j];
            if(dis[i][j]%2 == 1) c = (c == '#'?'.':'#');
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}