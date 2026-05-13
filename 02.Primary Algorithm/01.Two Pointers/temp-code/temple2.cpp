//不定滑窗模板<https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences>
/*
给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, left = 0, cnt[26]{};
        for (int i = 0; i < s.length(); i++) {
            int b = s[i] - 'a';
            cnt[b]++;
            //不定在这里,从左指针向右遍历一个范围找答案
            while (cnt[b] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, i - left + 1);//注意答案选取的地方 
        }
        return ans;
    }
};