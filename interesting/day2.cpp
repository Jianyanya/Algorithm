//https://sim.csp.thusaac.com/contest/38/problem/1
#include<iostream>
#include<queue>
#include<cstring>
#include<utility> 
using namespace std;
const int N = 101;
int vis[N][N] = {0};
int DIR[8][2] = {{2,-1},{2,1},{1,2},{1,-2},{-2,-1},{-2,1},{-1,2},{-1,-2}};
int n,k,a,b; 
int main()
{
	cin>>n>>k>>a>>b;
	queue<pair<int,int> > q;
	q.push({a,b});
	vis[a][b] = 1;
	int ans = 1;
	while(!q.empty()&&k>0){
		int size = q.size();
		for(int i = 0;i<size;i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for( auto d:DIR){
				int nx = x+d[0];
				int ny = y+d[1];
				if(nx>0&&nx<=n&&ny>0&&ny<=n&&!vis[nx][ny]){
					ans++;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
		}
		k--;
	}
	cout<<ans;
	return 0;
}

