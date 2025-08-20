//题目来源<https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points>
//一道简单的模拟题,因为我第一次做卡住了,所以给大家做做...
//模拟题大多考察处理数据的技巧,和链表没太大关系
//第一次卡在如何判断极值,链表不能随机访问,单链表只能记录该节点的值和后面节点的值
//所以直接定义一个变量pre记录就行
//最大值一定在最左端和结束端,最小值一定在相邻端
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
 };

 //答案部分
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mindistence = INT_MAX,maxdistence = -1;;
        int a = head->val,left = -1,id = 1,preid = -1;
        ListNode *cur = head->next;
        while(cur->next){
            if((a>cur->val&&cur->next->val>cur->val)||(a<cur->val&&cur->next->val<cur->val)){
                if(left==-1){
                    left = id;
                    preid = id;
                }else{
                    mindistence = min(mindistence,id-preid);
                    preid = id;
                    maxdistence = id-left;
                }
            }
            a = cur->val;
            id++;
            cur = cur->next;
        }
        if(maxdistence ==-1) return {-1,-1};
        return {mindistence,maxdistence};
    }
};