//poj-3278-农夫抓牛,题目链接<http://poj.org/problem?id=3278>
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;
const int N = 100001;
int b,d;
bool vis[N];
int main() {
    cin>>b>>d;
    queue<int> q;
    q.push(b);
    vis[b] = true;
    int ans = 0;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            int x = q.front();q.pop();
            if(x==d){
                cout<<time;
                return 0;
            }
            if(x+1<N&&!vis[x+1]) q.push(x+1),vis[x+1] = true;
            if(x-1>=0&&!vis[x-1]) q.push(x-1),vis[x-1] = true;
            if(2*x<N&&!vis[x*2]) q.push(2*x),vis[2*x] = true;
        }
        time++;
    }
    return 0;
}