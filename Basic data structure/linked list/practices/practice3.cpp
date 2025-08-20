//题目链接<https://leetcode.cn/problems/split-linked-list-in-parts>
//关键点:均摊方法,断开链表存储
//主要是对于均摊的处理
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> arr(k);
        ListNode *cur = head;
        int len = 0;
        while(cur) len++,cur = cur->next;
        int n = len/k;//先看能分成多少段
        int rem = len%k;//再把多余的求出来,均摊到前面的部分
        int index = 0;
        cur = head;
        for(int i = 0;i<k&&cur;i++){
            arr[i] = cur;//储存当前节点
            //rem>0来判断均摊数
            for(int i = 1;i<n+(rem>0);i++){
                cur = cur->next;//移动到要断开的点
            }
            ListNode *p = cur->next;//断开前先得到该节点的下一个指针
            cur->next = nullptr;//断开
            cur = p;//继承下一个指针位子,继续循环
            rem--;
        }
        return arr;
    }
};