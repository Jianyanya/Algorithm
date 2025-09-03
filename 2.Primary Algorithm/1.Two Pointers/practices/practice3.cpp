//First one-hdu-5358,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=5358>
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
int mylog(long long n){
    if(n<=1) return 0;
    int ans = 0;
    while(n%2==0){
        n /= 2;
        ans++;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    while(n--){
        int m;cin>>m;
        vector<long long> arr(m+1);
        for(int i = 1;i<=m;i++){
            int p;cin>>p;
            arr[i] = arr[i-1]+p;
        }
        long long ans = 0;
        for(int i = 1;i<=m;i++){
            for(int j = i;j<=m;j++){
                long long sum = arr[j]-arr[i-1];
                int lg = mylog(sum);
                ans += (abs(lg)+1)*(i+j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}