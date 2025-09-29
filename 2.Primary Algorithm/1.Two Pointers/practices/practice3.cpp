//First one-hdu-5358,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=5358>
//考察三指针运用
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
p-i ->log2 = t;p-i = t^2 <=> p = t^2+i;
q-i ->log2 = t;->4~8
既然枚举t了,那么不就反过来知道log2处理后的结果了吗,不用进行log2处理了
4.三指针,枚举i为匹配目标,用二分法找到对应的上界,再进行下标的计算就行了
5.由于i和j都是等差增加,以直接使用等差求和得到答案,避免逐个累加
这个就太简单了,(定值+1)*(i+j),且i不变,j为等差数列a(n) = i+n,直接上公式
时间复杂度,遍历一次加枚举和二分搜索(n*32*log(n))->O(n*log(n)),题目数值在1e5左右,与算法书上给的一模一样,简直完美
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