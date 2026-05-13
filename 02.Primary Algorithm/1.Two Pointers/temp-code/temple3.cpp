//lc,题目链接<https://leetcode.cn/problems/subarray-sum-equals-k/description/>
//恰好型滑窗,这里使用枚举右维护左的技巧解题

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1);
        //求前缀和
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1]+nums[i-1];
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += mp[pre[i]-k];
            mp[pre[i]]++;
        }
        return  ans;
    }
};