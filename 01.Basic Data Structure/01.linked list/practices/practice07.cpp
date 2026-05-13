//题目链接<https://leetcode.cn/problems/delete-node-in-a-linked-list>
//这道题有点为题出题,主要是链表中的处理技巧,脑筋急转弯吧
//怎么思考来的呢?
//我们都知道,要删除非头节点,一般都要记录当前指针和前一个指针,以方便前面与后面相连,我们要记住,无论如何都是这样,删除操作一定是这样
//那这道题就说无法访问第一个节点,给出中间节点让你删除,意思就是你不知道上一个节点的指针,然后让你进行删除操作
//既然我们无法获取上一个指针,那就把重心放在后面,删除不一定非得把目前的数真正的删掉,在数组中,要删除哪个点是不是把该点后面的所有数往前移,就是覆盖操作,那么这里也是一样
//简单说,你删不了当前节点,但可以删下一个节点啊,把当前节点变成下一个节点,再把下一个节点删了不就行了
//1->2->3->4 => 1->3->3->4 => 1->3->4;
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        return;
    }
};