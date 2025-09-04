//First one-hdu-5358,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=5358>
//考察三指针运用
/*
解题思路:
1.对于log2就是求2的多少次幂,直接用位运算可以解决
2.题目很好实现,要求范围和就用前缀和预处理,把范围累加变成两数相差
3.主要优化点在双重循环中,但貌似这个循环是不可避免的,可以发现在8到16中间的数进行log2处理后得到的值是一样的,所以有一定范围的值是相等的,可以简化计算
4.三指针,以i为匹配目标,用二分法找到对应的相同log2数值的范围(左右),再进行范围的匹配
5.由于i和j都是等差增加,以直接使用等差求和得到答案,避免逐个累加
时间复杂度,题目数值在1e5左右,能承受的时间为O(nlog以2为底n),这个题目经过优化大约n(log以2为底n)^2,是可以接受的
*/
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