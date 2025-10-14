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
p-(i-1) ->log2 = t;p-(i-1) = 2^t <=> p = 2^t+i-1;
q-i ->log2 = t;->4~8
既然枚举t了,那么不就反过来知道log2处理后的结果了吗,不用进行log2处理了
4.三指针,枚举i为匹配目标,用二分法找到对应的上界,再进行下标的计算就行了
5.由于i和j都是等差增加,以直接使用等差求和得到答案,避免逐个累加
这个就太简单了,(定值+1)*(i+j),且i不变,j为等差数列a(n) = i+n,直接上公式
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int a;
        vector<ll> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a;
            prefix[i] = prefix[i - 1] + a;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            int j = i;
            while(j <= n){
                ll sum = prefix[j] - prefix[i - 1];
                if(sum == 0){
                    int k = j;
                    while(k <= n && prefix[k] == prefix[i - 1]) k++;
                    k--;
                    int cnt = k - j + 1;
                    ans += 1LL*cnt * i + 1LL*(j + k) * cnt / 2;// t=0, 所以(t+1)=1
                    j = k + 1;
                    continue;
                }
                int t = 0;
                ll temp = sum;
                while(temp > 1){
                    t++;
                    temp >>= 1;
                }
                ll lower = (1LL << t);
                ll upper = (1LL << (t + 1)) - 1;
                int left = j, right = n, R = j;
                while(left <= right){
                    int mid = (left + right) / 2;
                    ll sum_mid = prefix[mid] - prefix[i - 1];
                    if(sum_mid <= upper){
                        R = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                int cnt = R - j + 1;
                ans += (t+1)*(1LL*cnt * i + 1LL*(j + R) * cnt / 2);
                j = R + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}