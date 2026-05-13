//First one-hdu-5358,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=5358>
/*
解题思路:
我先写出我第一次写的思路,因为是正确的所以还是记录一下
1----
由于区间0 - 1,2 - 3,4 - 7,8 - 15,这些区间内的log2的值是相同的,所以利用这个做区间查询统一计算
处理得到前缀和数组后,数组为单调递增的(ai>0),故可以使用二分找这个区间的上下界
要枚举2的k次幂直到34或35
即找到一个区间2^k < sum[l] ... sum[r] < 2^(k+1),即pre[l] - pre[i] ~ pre[r] - pre[l];
直接找这个区间就行,计算(i+j),因为是连续的等差数列,直接套公式即可计算,这个题就得解了,时间复杂度为o(35*nlogn)
2---最优解
1解法中只能处理数组数值都大于0的情况,最优解可以处理负数情况
由于log2(0) = 0,有特殊情况,可以优先处理,同时(log2(sum[i]) + 1)可知最小贡献为1,所以先计算累加一遍为1的所有答案
我们在这里就不用处理前缀和了,我们直接枚举2的幂值为s,那么接下来就是在数组中找到大于s的数组范围,可以使用双指针做法
找到后怎么计算答案,由于我每次只统计了一次贡献,后面更大的数也有一层贡献,所以计算(l ~ n)的值
(l + r) + (l + r + 1) + (l + r + 2) ....(l + n)
设cnt = n - l + 1;
cnt * l + (r + 1) + (r + 2)... + n
得cnt * l + (r + n)*cnt/2;
每次累加就行
*/
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
typedef long long ll;

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<ll> arr(n+1);
        ll sum = 0,ans = 0;
        for(int i = 1;i<=n;i++){
            cin>>arr[i];sum += arr[i];
            ll cnt = n - i + 1;
            ans += i*cnt + (ll)(i + n)*cnt/2;
        }
        for(ll s = 2;s<=sum;s <<= 1){
            int r = 1;
            ll res = 0;
            for(int l = 1;l<=n;l++){
                if(l > r){
                    r = l;
                    res = 0;
                    continue;
                }
                while(r<=n && res < s){
                    res += arr[r++];
                }
                if(res >= s){
                    int right = r - 1;
                    ll cnt = n - right + 1;
                    ans += (ll)l*cnt + (right + n)*cnt/2;
                }
                res -= arr[l];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}