/*
对于每个区间的查询,外层必然是O(n)的遍历
对于内层,必须要优化成O(logn)以下的时间
对于直接暴力做法,要至少遍历区间一遍
发现不可能有O(1)的做法
因为数组中还分为许多个递增的区间,每个区间的值是不同的,但是都是递增的
考虑使用前缀和预处理递增序列
但是对于每个区间的查询在开始的头时有偏差,这个偏差来自于开始的数组不连续
1,2,3,1,2,3,4
1,2,6,7,9,12,16
我要查询2,3的,但是6-1=5,所以这个偏差是数组长度,但是对于后面的区间来说是不影响的
可以记录数组的nums[i-1]>nums[i]的每个位置,放到数组中,再直接进行二分查找,l<index<r
要特殊处理的就只有头和尾,因为数组中记录的下标就是最近的,所以可以快速定位计算
数组中记录的下标,是具有单调性的,所以可以二分查找上下边界,再遍历计算
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> start(n);
        start[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) start[i] = start[i-1];
            else start[i] = i;
        }
        vector<long long> pre(n);
        pre[0] = start[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pref[i-1] + start[i];
        }
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            int low = l, high = r, p = r + 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (start[mid] >= l) {
                    p = mid;
                    high = mid - 1;
                }else low = mid + 1;
            }
            long long total = 0;
            total = (long long)(l + r + 2) * (r - l + 1) / 2;
            if (p > r) total -= (long long)l * (r - l + 1);
            else {
                if (p > l) total -= (long long)l * (p - l);
                long long ss = pre[r] - (p > 0 ? pre[p-1] : 0);
                total -= ss;
            }
            ans[i] = total;
        }
        return ans;
    }
};