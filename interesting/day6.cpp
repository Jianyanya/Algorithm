#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define PII pair<int,int>
const int N=2e5+10;
void solve(){
	int n;
	cin >>n;
	cout << "Yes" <<endl;
	if(n>3)
	{
		int a=2*n-3,b=2*n-2,c=2*n-1,d=2*n;
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout << i << ' ' ;
			}
			cout << endl;;
		}
		int js=0;
		for(int i=1;i<=2;i++)
		{
			for(int j=n-1;j<n-1+n;j++)
			{
				js++;
				if(js==n-1)cout << a << ' ';
				else if(js==n)cout << b << ' ';
				else if(js==2*n-1)cout << c << ' ';
				else if(js==2*n)cout << d << ' ';
				else cout << j <<' ';
			}
			cout << endl;
		}
	}
	if(n==2)
	{
		cout << 1 << ' ' <<2 << endl;
		cout << 3 << ' ' << 4 << endl;
	}
	if(n==3)
	{
		cout << 3 << ' ' << 2 << ' ' << 6 << endl;
		cout << 4 << ' ' << 3 << ' ' << 3 << endl;
		cout << 3 << ' ' << 1 << ' ' << 5 << endl;
	}
}	 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q=1;
	while(q--)
	solve();
}