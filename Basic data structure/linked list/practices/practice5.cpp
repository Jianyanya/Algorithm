//题目链接<https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array>
//还是头节点特判
//但是leetcode的测试环境似乎优化的很好,当我使用head = head->next;时,明明会内存泄漏,但是环境自动释放了,再去删除就会报"访问不存在的内存错误";
//所以只能使用head = head->next,只有在开发环境下才需要注重内存泄漏问题
//一般做题都可以忽略,比如爆栈等问题;
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //leetcode支持高版本的c++,所以有contains,可以使用find来查询,或者set插入
        //st.find(head->val)!=st.end();事实这个快些,但contains好写
        //st.insert(head->val).second;
        //可以发现都要遍历一遍nums,但似乎没有其他办法
        unordered_set<int> st(nums.begin(),nums.end());
        while(head&&st.contains(head->val)) head = head->next;
        if(!head) return head;
        ListNode *pre = head,*now = head->next;
        while(now){
            if(st.contains(now->val)){
                pre->next = now->next; 
                delete now;
                now = pre->next;
            }else{
                pre = now;
                now = now->next;
            }
        }
        return head;
    }
};