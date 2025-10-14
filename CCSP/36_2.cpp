#include<iostream>
#include<vector>
using namespace std;
int n; 
/*
3
9 4 6 2
9 4 6

15 10 9
*/
//9 4 6 2
//0 9 9 9
//9 6 6 2
int main(){
	cin>>n;
	vector<int> arr(n+1);
	vector<int> bt(n+1);
	vector<int> w(n+1); 
	vector<int> pre_mx(n+1);
	vector<int> suf_mx(n+1); 
	for(int i = 0;i<=n;i++){
		cin>>arr[i];
	} 
	for(int i = 1;i<=n;i++){
		cin>>bt[i];
	}
	w[0] = arr[0]; 
	for(int i = 1;i<=n;i++){
		w[i] = w[i-1]+arr[i]-bt[i];
	}
	pre_mx[1] = w[0];
	for(int i = 2;i<=n;i++){
		if(pre_mx[i-1]<w[i-1]) pre_mx[i] = w[i-1];
		else  pre_mx[i] = pre_mx[i-1];
	}
	suf_mx[n] = w[n];
	for(int i = n-1;i>0;i--){
		if(w[i]>suf_mx[i+1]) suf_mx[i] = w[i];
		else suf_mx[i] = suf_mx[i+1];
	}
	for(int i = 1;i<=n;i++){
		if(pre_mx[i]>bt[i]+suf_mx[i]) cout<<pre_mx[i];
		else cout<<bt[i]+suf_mx[i];
		cout<<" "; 
	}
	return 0;
} 
