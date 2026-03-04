//经典的括号匹配问题,leetcode-3703-移除K-平衡子字符串,题目链接<https://leetcode.cn/problems/remove-k-balanced-substrings>
/*
有两种做法
1.单字符栈
可以直接使用string充当栈进行操作,string的本质就是char数组,所以可以当栈使用
原理很简单,就是计算匹配,每次当连续')'出现k次后,就检查栈中'('的数目,符合的话,就进行出栈操作出栈2*k次
因为必须枚举完后才能知道符合数量的'(',所以效率低下且不好操作
2.使用pair<char,int>
也是一个技巧,统计每个连续的符号的数量进行储存,每次枚举时检查栈顶的元素,相同则合并
不同则可以快速知道对应的数量,然后进行判断匹配
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeSubstring(string s, int k) {
    string st = "";
    for (char c : s) {
        st.push_back(c);
        if (c == ')' && st.size() >= 2 * k) {
            bool isKBalanced = true;
            for (int i = 0; i < k; i++) {
                if (st[st.size() - 2 * k + i] != '(') {
                    isKBalanced = false;
                    break;
                }
            }
            for (int i = 0; i < k; i++) {
                if (st[st.size() - k + i] != ')') {
                    isKBalanced = false;
                    break;
                }
            }
            if (isKBalanced) {
                st.resize(st.size() - 2 * k);
            }
        }
    }
        return st;
    }
};
class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char,int>> st;
        for(char &c:s){
            if(!st.empty()&&st.back().first==c) st.back().second++;
            else st.push_back({c,1});
            if(c==')'&&st.size()>=2&&st.back().second==k&&st[st.size()-2].second>=k){
                st.pop_back();
                st.back().second -= k;
                if(st.back().second==0) st.pop_back();
            }
        }
        string ans = "";
        for(auto &p:st){
            ans += string(p.second,p.first);
        }
        return ans;
    }
};