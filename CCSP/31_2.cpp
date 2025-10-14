#include<iostream>
#include<math.h>
#include<vector>
#include<cstdio>
using namespace std;
int n,m; 
/*
10 5
2 0.59
2 4.956
1 0.997
1 1.364
1 1.242
1 0.82
2 2.824
1 0.716
2 0.178
2 4.094
1 6 -953188 -946637
1 9 969538 848081
4 7 -114758 522223
1 9 -535079 601597
8 8 159430 -511187

-1858706.758 -83259.993
-1261428.46 201113.678
-75099.123 -738950.159
-119179.897 -789457.532
114151.88 -366009.892
*/
/*
*/
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
		cout<<endl;
	}
	return 0;
} 
