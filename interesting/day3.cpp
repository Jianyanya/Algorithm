#include<bits/stdc++.h>
using namespace std;
//直接取最小平均前缀
/*

*/
class Solution{
    const int N = 1e5+10;
int n,k;
int arr[N];
int main(){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans =INT_MAX ;
    for(int i = 0;i<k;i++){
        int sum = 0;
        int cnt = 0;
        for(int j = i;j<n;j+=k){
            sum += arr[j];
            cnt++;
            ans = min(ans,sum/cnt);
        }
    }
    cout<<ans;
    return 0;
}
};