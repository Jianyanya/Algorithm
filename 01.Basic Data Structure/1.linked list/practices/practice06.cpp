//题目链接<https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii>
//这道题的难点还是头节点不好处理,而且链表已经按照递增排序,相同的数据聚在一起
//跳过相同的节点就行
//既然头节点难以处理,那我就往头节点前插一个假的头节点不就行了
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0,head);//设头节点
        ListNode *cur = &ans;//记录答案头位置
        while(cur->next&&cur->next->next){//从假的头节点的下一位开始
            int val = cur->next->val;
            if(cur->next->next->val==val){
                //把相同的节点全跳过
                while(cur->next&&cur->next->val==val) cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return ans.next;//要返回ListNode*
    }
};
