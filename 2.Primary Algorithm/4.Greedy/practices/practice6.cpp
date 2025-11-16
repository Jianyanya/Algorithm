//cf,题目链接<https://codeforces.com/problemset/problem/2121/E>

#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T;
sr l,r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>l>>r;
        int n = l.size();
        bool flage = true;
        for(int i = 0;i<n;i++){
            if(l[i]==r[i]) continue;
            if(r[i]-l[i]>1){
                flage = false;
                cout<<i*2<<endl;
                break;
            }
            else{
                flage = false;
                int j = i+1;
                for(;j<n&&l[j]=='9'&&r[j]=='0';j++){
                }
                cout<<i+j<<endl;
                break;
            }
        }
        if(flage) cout<<n*2<<endl;
    }
    return 0;
}