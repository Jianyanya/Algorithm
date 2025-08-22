//题目链接<https://leetcode.cn/problems/remove-nodes-from-linked-list>
//中文题目有问题,请看英文,或者理解样例
//递归你一定熟悉,那当链表遇到递归呢
//递归就是从尾到头遍历,你可能会疑惑为什么要从尾开始遍历删除
//因为我们总要以后面的值与前面比较,这时从前面开始遍历,可能不知道后面的值,所以从后往前遍历,留下符合条件的值
//你肯定会想head->next->val>head->val进行比较,你可以试试,前一个节点怎么办;
//还可以用单调栈来做,不在此题范围
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *newhead = removeNodes(head->next);
        if(head->val<newhead->val) return newhead;
        head->next = newhead;
        return head;
    }
};