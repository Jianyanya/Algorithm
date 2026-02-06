//高精度乘法
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
    vector<int> arr(a+b+1);
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            int num1 = s1[i] - '0',num2 = s2[j] - '0';
            arr[i+j] += num1*num2;
        }
    }
    int t = 0;
    string ans = "";
    for(int i = a+b-2;i>=0;i--){
        int w = arr[i]+t;
        t = w/10;
        w %= 10;
        char c = '0' + w;
        ans = c + ans;
    }
    if(t!=0) ans = '1' + ans;
    int size = 0;
    while(ans[size]=='0'&&size<a+b-2) size++;
    for(int i = size;i<a+b;i++) cout<<ans[i];
    return 0;
}