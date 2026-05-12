//First one-hdu-5358,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=5358>
//考察三指针运用,题目难度目测2200
/*
解题思路:
1.对于log2就是求2的多少次幂,直接用位运算可以解决
2.题目很好实现,要求范围和就用前缀和预处理,把范围累加变成两数相差
即使是两数差还是O(n^2),但是所以还得继续
3.主要优化点在双重循环中,可以发现在8到16中间的数进行log2处理后得到的值是一样的,所以有一定范围的值是相等的,可以简化计算
怎么找到这个范围,在这个范围里,q为上界,p为下界,那么q-i和p-i都得到一个数,这个数对log2处理后值是相同的t
i -> p~q;
每次只用查找上界就行,下界为当前元素,当前为i,上界为bond
双变量怎么变单变量,我们看有多少个未知数,我们在枚举i,计算p,枚举p显然是不可能的,所以枚举t,t最多就枚举32次,且到大于数组中的最大值时就结束
p-(i-1) ->log2 = t;p-(i-1) = 2^t <=> p = 2^t+i-1;
q-i ->log2 = t;->4~8
既然枚举t了,那么不就反过来知道log2处理后的结果了吗,不用进行log2处理了
4.三指针,枚举i为匹配目标,用二分法找到对应的上界,再进行下标的计算就行了
5.由于i和j都是等差增加,以直接使用等差求和得到答案,避免逐个累加
这个就太简单了,(定值+1)*(i+j),且i不变,j为等差数列a(n) = i+n,直接上公式
时间复杂度,遍历一次加枚举和二分搜索(n*32*log(n))->O(n*log(n)),题目数值在1e5左右,与算法书上给的一模一样,简直完美
实现细节:
用前缀和计算区间和时,我们要每次枚举的是该点的前一位,还要注意枚举一位时的特殊情况,提高效率自己写pow函数
事实证明题目中给的log2(0)为0这种情况是非特殊情况,因为查找1的时候包括了0,没找到也能正常计算
在处理最后的一个大于等于数组中最大的数时,要退出循环并计算最后一段
在枚举t的时候,会有几个t实际上是没用的,而每次都进行二分查找,会在某个点上重复进行计算,所以每个点只能计算一次
使用stl库中的lower_bound和upper_bound,但是这两个都不符合我想的要求
一个月了,终于解决了,真的是太强了!!!
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