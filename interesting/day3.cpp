#include <bits/stdc++.h>
using namespace std;

bool f(long long m){
    int a = 0,b = 0, c = 0;
    while(m>0){
        int p = m%10;
        if(p==2) a++;
        else if(p==0) b++;
        else if(p==6) c++;
        m/=10;
    }
    return (a==2&&b==1&&c==1);
}
int main()
{
    int cnt = 0;
    //2026;
    for(long long i = 2026;i<=20262026;i++){
        if(f(i)) cnt++;
    }
    cout<<cnt;
  return 0;
}