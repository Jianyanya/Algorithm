//约瑟夫问题-洛谷-p1996,题目链接<https://www.luogu.com.cn/problem/P1996#ide>
//动态链表做法
#include<bits/stdc++.h>
using namespace std;
//链表做法,分为动态链表和静态链表,还有stl库中的list
//动态链表做法,最标准的教科书式做法
//优点是可以及时释放内存,缺点是需要管理空间容易出错
//本节代码纯教科书式,不符合竞赛代码,你非要这样写也行
struct node{
    int data;
    node *next;
}; 
int main(){
    int n,m;cin>>n>>m;
    node *head,*p,*now,*pre;
    head = new node;head->data = 1,head->next = NULL;
    now = head;
    for(int i = 2;i<=n;i++){
        p = new node;p->data = i,p->next = NULL;
        now->next = p;
        now =  p;
    }
    now->next = head;//链接首尾
    pre = now,now = head;//要进行删除操作,要读取删除节点的前一个节点和该节点
    while((n--)>1){
        for(int i = 1;i<m;i++){//因为链表的特性,可以直接删除链表节点
            pre = now;
            now = now->next;
        }
        cout<<now->data;
        //进行删除操作
        pre->next = now->next;
        delete now;
        now = pre->next;
    }
    cout<<now->data;
    delete now;
    //打印链表
    // while(head->next!=NULL){
    //     cout<<head->data;
    //     head = head->next;
    // }
    return 0;
}