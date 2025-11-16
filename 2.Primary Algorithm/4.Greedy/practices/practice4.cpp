//cf,题目链接<https://codeforces.com/problemset/problem/1845/C>
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T,n;
sr t,l,r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>t>>n>>l>>r;
        int m = t.size();
        vector<array<int,10>> nxt(m+1);
        fill(nxt[m].begin(),nxt[m].end(),m);
        for(int i = m-1;i>=0;i--){
            nxt[i] = nxt[i+1];
            nxt[i][t[i]-'0'] = i;
        }
        bool flage  = true;
        int ans = -1;
        for(int i = 0;i<n;i++){
            int index = ans+1;
            for(char c = l[i];c<=r[i];c++){
                ans = max(ans,nxt[index][c-'0']);
            }
            if(ans>=m){
                cout<<"YES";
                flage = false;
                break;
            }
        }
        if(flage) cout<<"NO";
        cout<<endl;
    }
    return 0;
}