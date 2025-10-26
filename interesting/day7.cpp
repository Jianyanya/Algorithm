//序列分割
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int a[N];
void solve(){
	int n;cin>>n;
	    for(int i=1;i<=n;i++)cin>>a[i];
	    for(int i=n-1;i>=1;i--)a[i]+=a[i+1];
	    sort(a+2,a+n+1);
	    int sum=a[1];
	    cout<<sum<<" ";
	    for(int i=n;i>=2;i--) {
	        sum+=a[i];
	        cout<<sum<<" ";
	    }
	    cout<<endl;
}	 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q=1;
	cin >> q;
	while(q--)
	solve();
    return 0;
}