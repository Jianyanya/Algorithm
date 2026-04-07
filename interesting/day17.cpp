#include<bits/stdc++.h>
using namespace std;

int main(){
    //1.
    int a,b;cin>>a>>b;
    cout<<a<<" + "<<b<<" = "<<a+b;
    //2.
    string str;getline(cin,str);
    int a = 0,b =0,c = 0;
    for(int i  = 0;i<str.size();i++){
        if(str[i]==' ') c++;
        else if(str[i]>='0'&&str[i]<='9') b++;
        else a++;
    }
    cout<<"letters="<<a<<" digits="<<b<<" spaces="<<c;
    //3.
    int n;scanf("%d",&n);
    double ans = 0;
    for(int i =0;i<n;i++){
        double a;scanf("lf",&a);
        ans += a;
    }
    printf("%.2lf",ans/n);
    //4.
    return 0;
}