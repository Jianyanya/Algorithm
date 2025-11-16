//lc-KMP模板题,题目链接<https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string target, string str) {
        //获取str的next数组
         int n = str.size();
         vector<int> next(n);
         int cnt = 0;
         for(int i = 1;i<str.size();i++){
            char c = str[i];
            while(cnt&&str[cnt]!=c)
                cnt = next[cnt-1];
            if(str[cnt]==c) cnt++;
            next[i] = cnt;
         }
         //在target目标字符串上找str片段,返回第一个匹配到的起点
         for(int i = 0,j = 0;i<target.size();i++){
            while(j&&str[j]!=target[i]) j = next[j-1];
            if(target[i]==str[j]) j++;
            if(j==n) return i-n+1;
         }
         return -1;
    }
};