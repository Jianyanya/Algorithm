//用结构体数组实现静态链表的做法
#include<bits/stdc++.h>
using namespace std;
//使用预分配连续内存空间储存链表,与动态链表不同的就是链表本身优点就是能克服连续储存的弊端,使不连续的内存空间可以联系起来,如果你这都不清楚,可以先学习一下数据结构相关内容
//<https://www.bilibili.com/video/BV1tNpbekEht/share_source=copy_web&vd_source=5f8341a44e1483521e03c09bc590e257>
//推荐这位老师讲的
//因为本身竞赛不需要严格管理内存,所以可以直接模拟链表来理论实现
const int N = 101;//题目中n给出的范围
struct node{
    int id,nextId;//这里面的操作全都跟动态链表一样
}nodes[N];
int main(){
    int n,m;cin>>n>>m;
    nodes[0].nextId = 1;//相当于头节点加个null,没用,但是养成好习惯
    for(int i = 1;i<=n;i++) nodes[i].id = i,nodes[i].nextId = i+1;//初始化链表
    nodes[n].nextId = 1;//首尾相连
    int now = 1,pre = 1;//同样记录前一个节点和该节点,删!
    while((n--)>1){
        for(int i = 1;i<m;i++){//头是0,所以从1开始遍历
            pre = now;
            now = nodes[now].nextId;
        }
        cout<<nodes[now].id<<" ";
        nodes[pre].nextId = nodes[now].nextId;
        now = nodes[pre].nextId;
    }
    cout<<nodes[now].id;
    return 0;
}