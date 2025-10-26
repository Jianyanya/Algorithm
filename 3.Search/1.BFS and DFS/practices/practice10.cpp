//poj-洗牌-3087,题目链接<http://poj.org/problem?id=3087>
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
#include<unordered_map>
using namespace std;
int T,n,ans;
string s1,s2,dest;
unordered_map<string,int> mp;
/*
H H
A A
A A
H H
HHAAAAHH
*/
void dfs(string str,int j){
    mp[str]++;
    if(str==dest){
        ans = j;
        return;
    }
    s1 = str.substr(n);
    s2 = str.substr(0,n);
    string temp = "";
    for(int i = 0;i<n;i++){
        temp += s2[i];
        temp += s1[i];
    }
    //cout<<temp<<endl;
    if(!mp[temp]) dfs(temp,j+1);
}
int main() {
    cin>>T;
    for(int i = 1;i<=T;i++){
        cin>>n>>s1>>s2>>dest;
        ans = -1;
        string str = "";
        for(int j = 0;j<n;j++){
            str += s2[j];
            str += s1[j];
        }
        //cout<<str<<endl;
        dfs(str,1);
        cout<<i<<" "<<ans<<endl;
    }
    return 0;
}