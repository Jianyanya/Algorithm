//不定滑窗poj-3061,题目链接<http://poj.org/problem?id=3061>
//经典不定滑窗
#include<bits/stdc++.h>
using namespace std;
int help(vector<int> a,int s){
    int n = 0;
    int ans = INT_MAX;
    for(int i = 0,j = 0;i<a.size();i++){
        n += a[i];
        while(j<=i&&n>s){
            ans = min(ans,i-j+1);
            n -= a[j++];
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        vector<int> arr(a);
        for(int i = 0;i<a;i++) cin>>arr[i];
        cout<<help(arr,b)<<endl;
    }
    return 0;
}