//碗子数组的数目-leetcode-3676,题目链接<https://leetcode.cn/problems/count-bowl-subarrays>
/*
这个题脑海中要有个碗的模型,碗两端大,我们不用特别去关注左右端的比较
作为左端点一个数要成碗,向右搜索到第一个大于自己的数
为什么是第一个,因为中间的数都小于自身和这个右端点是符合的,若再向右寻找,小的不满足大于中间数,大的左边不满足大于中间
右边同理,这个思路要把数组顺序和倒序遍历两边,必定超时
想想如何只遍历一边?既然是碗,反正左右边必须最大,我们可以先让左部分保持单调递减,这样所有单调的数必然组合碗的一半,这样我们只用讨论右边的情况就行
使用单调栈来维护左,列如5,3,1;当找到一个大的数4要使用栈内元素出栈时,那么不就是找到碗的右端了吗,把1踢出[3,1,4]为一组答案,再把3踢出剩5,4,[5,3,1,4]为一组答案
详细解释:已经保证栈内元素单调,那么中间的元素都比左边小,1比3小,1比4小,所以[3,1,4],3出栈时,1已经比3和4都要小,可以直接忽略,比较3和4大小
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        for(int x:nums){
            while(!st.empty()&&st.top()<x){
                st.pop();
                if(!st.empty()) ans++;
            }
            st.push(x);
        }
        return ans;
    }
};