//lc,题目链接<https://leetcode.cn/problems/binary-subarrays-with-sum/description/>
//恰好型滑窗核心技巧：恰好 = 最多 - 最多-1
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        auto check = [&](int k) -> int {
            if(k<0) return 0;
            int l = 0,sum = 0,ans = 0;
            for(int r = 0;r<n;r++){
                sum += nums[r];
                while(l<=r&&sum>k) sum -= nums[l++];
                ans += r-l+1;
            }
            return ans;
        };
        return check(goal) - check(goal-1);
    }
};
