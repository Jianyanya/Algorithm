#include<iostream>
#include<math.h>
#include<vector>
#include<cstdio>
using namespace std;
int n,m; 
int main(){
	scanf("%d %d",&n,&m);
	vector<double> pre_c(n+1);
	pre_c[0] = 1; 
	vector<double> pre_j(n+1);
	for(int i = 1;i<=n;i++){
		int a;double b;scanf("%d %lf",&a,&b);
		if(a==1) pre_c[i] = pre_c[i-1]*b,pre_j[i] = pre_j[i-1]; 
		if(a==2) pre_j[i] = pre_j[i-1]+b,pre_c[i] = pre_c[i-1];
	}
	while(m--){
		int l,r,X,Y;scanf("%d %d %d %d",&l,&r,&X,&Y);
		double k = pre_c[r]/pre_c[l-1];
		double p = pre_j[r] - pre_j[l-1];
		double x = k*X;
		double y = k*Y;
		printf("%.3f %.3f",x*cos(p)-y*sin(p),x*sin(p)+y*cos(p));
		printf("\n"); 
	}
	return 0;
} 