//题目链接<https://leetcode.cn/problems/remove-linked-list-elements>
//删除问题,清楚链表本来就是有头节点和无头节点之分
//别人说什么快慢指针,我看了一下,就是最基本的删除操作
//pre记录该节点的上一个指针
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
    ListNode* removeElements(ListNode* head, int val) {
        //对头节点特判,因为头节点没有pre
        while(head&&head->val==val){
            //可以直接head = head->next;但是内存泄漏了,但测试环境会自动处理;
            ListNode* tempNode = head;
            head = head->next;
            delete tempNode;
        }
        if(!head) return head;//若全删了,则直接返回
        ListNode *ans = head;//记录头节点位置,好返回答案
        ListNode *pre = head;
        head = head->next;
        while(head){
            if(head->val==val){//删除操作
                pre->next = head->next;
                delete head;
                head = pre->next;
            }else{
                pre = head;
                head = head->next;
            }
        }
        return ans;
    }
};