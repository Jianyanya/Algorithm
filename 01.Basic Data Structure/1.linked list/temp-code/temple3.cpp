//用结构体数组实现双向静态链表
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
//跟单链表没啥太大区别,主要还是介绍双向链表的应用,后面还有两个数组模拟双向链表的应用
struct node{
    int id;
    int preId,nextId;//上一个指针和下一个指针
}nodes[N];
int main(){
    int n,m;cin>>n>>m;
    nodes[0].nextId = 1;//好习惯
    for(int i = 1;i<=n;i++){
        nodes[i].id = i;
        nodes[i].preId = i-1;
        nodes[i].nextId = i+1;
    }
    nodes[n].nextId = 1,nodes[1].preId = n;//首尾向相连成环
    int now = 1;//储存当前节点,上一节点已经在结构体数组中储存,所以不用创建pre
    while((n--)>1){
        for(int i = 1;i<m;i++) now = nodes[now].nextId;//往后数m下
        cout<<nodes[now].id<<" ";
        //双链表比单链表的删除多一个操作
        int pre = nodes[now].preId,next = nodes[now].nextId;
        nodes[pre].nextId = next;//前连后
        nodes[next].preId = pre;//后连前
        now = next;
    }
    cout<<nodes[now].id;
    return 0;
}