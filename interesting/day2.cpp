#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ve<string> strs = {"10", "0001", "111001", "1", "0"}; 
    sort(strs.begin(),strs.end(),[](auto s1,auto s2){
        if(s1.size()==s2.size()) return s1>s2;
        else return s1.size()<s2.size();
    });
    for(auto s:strs){
        cout<<s<<endl;
    }
    return 0;
}