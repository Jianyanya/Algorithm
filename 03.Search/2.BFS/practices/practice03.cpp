//poj-3126-题目链接<http://poj.org/problem?id=3126>
/*
就是找最短路径的问题
比较简单,但是要先筛质数以减轻bfs的压力
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;
const int N = 10000;
bool isprime[N];
bool vis[N];
int T,a,b;
void init(){
    isprime[0] = isprime[1] = false;
    for(int i = 2;i<N;i++){
        if(isprime[i]){
            for(long long j = 1LL*i*i;j<N;j+=i){
                isprime[j] = false;
            }
        }
    }
}
int bfs(){
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(a);
    int cnt = 0;
    vis[a] = true;
    while(!q.empty()){
        int size = q.size();
        for(int t = 0;t<size;t++){
            int num = q.front();q.pop();
            //cout<<num<<endl;
            int temp = num;
            if(num==b) return cnt;
            int p = 1;
            for(int i = 1;i<=4;i++){
                int m = temp%10;temp /= 10;
                int num1 = num-p*m;
                for(int j = 0;j<=9;j++){
                    int prime = num1+p*j;
                    if(prime>=1000&&isprime[prime]&&!vis[prime]){
                        q.push(prime);
                        vis[prime] = true;
                    }
                }
                p *= 10;
            }
        }
        cnt++;
    }
    return -1;
}
int main() {
    memset(isprime, true, sizeof(isprime));
    init();
    cin>>T;
    while(T--){
        cin>>a>>b;
        int ans = bfs();
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}