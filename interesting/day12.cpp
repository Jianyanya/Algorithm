#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
vector<int> arr(1001);
vector<int> arrk(1001);
int n;
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
	for(int i = 0;i<n;i++) scanf("%d",&arrk[i]);
	queue<int> q;
	q.push(0);
	int ans= 100000000;
	int cnt  =0;
	vector<bool> ment(n+1,false); 
	while(!q.empty()){
		int size = q.size();
		for(int i = 0;i<size;i++){
			int index = q.front();q.pop();
			if(index==n-1){
				ans = cnt;
				cout<<ans;
				return 0;
			}
			index = index - arr[index];
			int d = arrk[index];
			for(int j = 1;j<=d&&index+j<n;j++){
				if(!ment[index+j]) q.push(index+j),ment[index+j] = true;
			}
		}
		cnt++;
	}
	cout<<-1;
	return 0;
}