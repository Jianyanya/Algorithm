//cf(贪心,矩阵,1200)<https://codeforces.com/problemset/problem/2069/B>
#include<bits/stdc++.h>;
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        vector arr(x,vector<int>(y,0));
        int mp[x*y+1] = {0};
        int ans = -1;
        int h = 0;
        for(int i = 0 ;i<x;i++){
            for(int j = 0;j<y;j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0 ;i<x;i++){
            for(int j = 0;j<y;j++){
                int t =  arr[i][j];
                if(mp[t]>=2) continue; 
                if((i>0&&arr[i-1][j]==t)||(j>0&&arr[i][j-1]==t)){
                    h = 1;
                    mp[t]++;
                    ans++;
                }else if(mp[t]==0) mp[t]++,ans++;
            }
        }
        cout<<ans-h<<endl;
    }
    return 0;
}