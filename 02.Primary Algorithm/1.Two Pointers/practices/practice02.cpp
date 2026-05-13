//Bound Found-poj-2566,题目链接<http://bailian.openjudge.cn/practice/2566>
//很难弄的一个题,双指针
/*
解题思路:
1. 这个题目就是求区间总和的绝对值最接近t的区间
2. 看到区间和想前缀和,在前缀和数组中找两个值相差绝对值接近t
3. 怎么找,直接枚举n^2,由于abs(pre[r] - pre[l]) == abs(pre[l] - pre[r]),即不用满足i<j,所以找任意位置的
4. 既然是任意位置,就对前缀数组进行排序,同时保留下标进行记录,然后使用滑动窗口就行
5. 实现细节: 对于每一次记录,都一定要先比较记录再进行对l,r的调整
输入:
5 1
-10 -5 0 5 10
3
10 2
-9 8 -7 6 -5 4 -3 2 -1 0
5 11
15 2
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
15 100
0 0
预期输出:
5 4 4 
5 2 8
9 1 1
15 1 15
15 1 15
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(){
        while(cin>>n>>m&&n!=0&&m!=0){
            vector<pair<ll,int> > arr;
            arr.push_back({0,0});
            for(int i = 1;i<=n;i++){
                int p;cin>>p;
                arr.emplace_back(arr[i-1].first + p,i);
            }
            sort(arr.begin(),arr.end());
            while(m--){
                int k;cin>>k;
                ll ans = 0,left = 1,right = 1,mn = INT_MAX;
                int l = 0,r = 1;
                while(l<=n&&r<=n){
                    if(l==r){
                        r++;
                        continue;
                    }
                    ll res = arr[r].first - arr[l].first;
                    ll df = llabs(res - k);
                    if(df < mn){
                        mn = df;
                        left = min(arr[r].second,arr[l].second) + 1;
                        right = max(arr[r].second,arr[l].second);
                        ans = res;
                    }
                    if(res > k) l++;
                    else if(res < k) r++;
                    else break;
                }
                cout<<ans<<" "<<left<<" "<<right<<endl;
            }
        }
    return 0;
}