#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        int m = (c-a)*100/b;
        int md = m%10+1;
        cout<<m/10+1<<" "<<md<<endl;
    }
    return 0;
}