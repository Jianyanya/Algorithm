//poj-3414-倒水,题目链接<http://poj.org/problem?id=3414>
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
#include<queue>
#include<set>
using namespace std;
int a,b,c;
string s;
int bfs(){
    queue<string> q;
    q.push("");
    queue<pair<int,int> > sq;
    pair<int,int> pr = make_pair(0,0);sq.push(pr);
    vector<vector<bool> > vis(a+1,vector<bool>(b+1,false));
    vis[0][0] = true;
    int ans = 0;
    while(!sq.empty()){
        int size = sq.size();
        for(int i = 0;i<size;i++){
            pair<int,int> p = sq.front();sq.pop();
            string strs = q.front();q.pop();
            if(p.first==c || p.second==c){
                s = strs;
                return ans;
            }
            //fill
            if(!vis[a][p.second]) sq.push(make_pair(a,p.second)),q.push(strs+'0'),vis[a][p.second] = true;
            if(!vis[p.first][b]) sq.push(make_pair(p.first,b)),q.push(strs+'1'),vis[p.first][b] = true;
            //drop
            if(!vis[0][p.second]) sq.push(make_pair(0,p.second)),q.push(strs+'2'),vis[0][p.second] = true;
            if(!vis[p.first][0]) sq.push(make_pair(p.first,0)),q.push(strs+'3'),vis[p.first][0] = true;
            //pour
            int sd = p.first>=b-p.second?b:p.first+p.second,ft = p.first>=b-p.second?p.first+p.second-b:0;
            if(!vis[ft][sd]) sq.push(make_pair(ft,sd)),q.push(strs+'4'),vis[ft][sd] = true;
            ft = p.second>=a-p.first?a:p.first+p.second;
            sd = p.first>=a-p.second?p.first+p.second-a:0;
            if(!vis[ft][sd]) sq.push(make_pair(ft,sd)),q.push(strs+'5'),vis[ft][sd] = true;
        }
        ans++;
    }
    return -1;
}
int main() {
    cin>>a>>b>>c;
    int re = bfs();
    if(re==-1) cout<<"impossible";
    else {
        cout<<re<<endl;
        for(int i = 0;i<s.size();i++){
            char d = s[i];
            if(d=='0') cout<<"FILL(1)";
            else if(d=='1') cout<<"FILL(2)";
            else if(d=='2') cout<<"DROP(1)";
            else if(d=='3') cout<<"DROP(2)";
            else if(d=='4') cout<<"POUR(1,2)";
            else if(d=='5') cout<<"POUR(2,1)";
            cout<<endl;
        }
    }
    return 0;
}