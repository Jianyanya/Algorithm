//csp-37-4,题目链接<>
/*
毕竟是第四题,算是非常难的了
但是一眼就能看出考点,三指针
数据范围符合该要求,循环方式类似,依旧是枚举每个数,进行范围匹配,二分找上界下界
核心难点:gcd的性质与相关知识,
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n;cin>>n;
	vector<int> arr(n+1);
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int ans =0;
	for(int l = 1;l<=n;l++){
		int num = arr[l];
		for(int r = l;r<=n;r++){
			num = gcd(num,arr[r]);
			ans = (ans+1LL*l*r*num%MOD)%MOD;
		}
	}
	cout<<ans;
	return 0;
}
