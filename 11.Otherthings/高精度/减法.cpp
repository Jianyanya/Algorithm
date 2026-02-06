//高精度减法
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include<utility>//poj不能用
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
using namespace std;

int main(){
    string s1,s2;cin>>s1>>s2;
    int a = s1.size(),b = s2.size();
    string ans = "";
    auto check = [&](string str1,string str2) -> string {
        int a1 = str1.size(),b2 = str2.size();
        for(int i = a1-1,j = b2 - 1;i>=a1-b2&&j>=0;i--,j--){
            if(str1[i]<str2[j]){
                int p = i-1;
                while(str1[p]=='0'){
                    str1[p] = '9';
                    p--;
                }
                str1[p]--;
                str1[i] = '0' + (str1[i] - str2[j] + 10);
            }else if(str1[i]>=str2[j]) str1[i] = '0' + (str1[i] - str2[j]);
        }
        return str1;
    };
    //相等则逐位判断大小
    bool gay = false;
    if(a==b){
        int flage = -1;
        for(int i = 0;i<a;i++){
            if(s1[i]>s2[i]){
                flage = 0;
                break;
            }else if(s1[i]<s2[i]){
                flage = 1;
                break;
            }
        }
        if(flage==1){
            gay = true;
            ans.append(check(s2,s1));
        }else ans.append(check(s1,s2));
    }else if(a>b){
        ans.append(check(s1,s2));
    }else{
        gay = true;
        ans.append(check(s2,s1));
    }
    if(gay) cout<<'-';
    bool p = true;
    for(int i = 0;i<ans.size()-1;i++){
        char c = ans[i];
        if(c=='0'&&p) continue;
        else{
            p = false;
            cout<<c;
        }
    }
    cout<<ans[ans.size()-1];
    return 0;
}