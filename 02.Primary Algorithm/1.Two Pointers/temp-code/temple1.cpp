//滑动窗口模板题<https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length>
/*
给你字符串 s 和整数 k 。
请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
英文中的 元音字母 为（a, e, i, o, u）。
因为实在太简单了,直接借灵神的模板了
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        for (int i = 0; i < s.size(); i++) {
            // 1. 进入窗口
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowel++;
            }
            if (i < k - 1) { // 窗口大小不足 k
                continue;
            }
            // 2. 更新答案
            ans = max(ans, vowel);
            if (ans == k) {
                break;
            }
            // 3. 离开窗口，为下一个循环做准备
            char out = s[i - k + 1];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
                vowel--;
            }
        }
        return ans;
    }
};