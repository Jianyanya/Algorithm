#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int x,y;cin>>x>>y;
        string str;cin>>str;
        for(char c:str){
            if((x<=n&&x>0&&y>0&&y+1<=n)&&c=='f') y = y+1;
            if((x<=n&&x>0&&y-1>0&&y<=n)&&c=='b') y = y-1;
            if((x<=n&&x-1>0&&y>0&&y<=n)&&c=='l') x = x-1;
            if((x+1<=n&&x>0&&y>0&&y<=n)&&c=='r') x = x+1;
        }
        cout<<x<<" "<<y;
        if(m>0) cout<<endl;
    }
    return 0;
}