//cf(贪心),题目链接<https://codeforces.com/problemset/problem/1914/D>

#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T,n;
ve<int> get_mx(ve<int> ar){
    int mx1 = -1,mx2 = -1,mx3 = -1;
    for(int i = 0;i<n;i++){
        if(mx1==-1||ar[i]>ar[mx1]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }else if(mx2 == -1||ar[i]>ar[mx2]){
            mx3 = mx2;
            mx2 = i;
        }else if(mx3==-1||ar[i]>ar[mx3]) mx3 = i;
    }
    return {mx1,mx2,mx3};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        ve<ve<int>> arr,nums;
        int ans = 0;
        for(int k = 0;k<3;k++){
            ve<int> ar(n);
            for(int i = 0;i<n;i++){
                cin>>ar[i];
            }
            nums.push_back(ar);
            arr.push_back(get_mx(ar));
        }
        for(int i:arr[0]){
            for(int j:arr[1]){
                for(int k:arr[2]){
                    if(i!=j&&i!=k&&j!=k) ans = max(ans,nums[0][i]+nums[1][j]+nums[2][k]); 

                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}