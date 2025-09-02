//操作系统-洛谷-p2278,题目链接<https://www.luogu.com.cn/problem/P2278>
//如何应用自定义对象堆
/*
用优先队列q来模拟我们的cpu
最开始时,cpu中没有进程,因此,我们把第一个进程放进去,第二个进程进来时会有选择
第一种情况,要进入的进程的开始时间在前面那个进程结束时间之后,我们相当于可以直接完场此时cpu中的进程,将时间节点更新当前结束时间
第二种情况,当前cpu中进程的结束时间在要进来的这个进程开始时间之,这是我们选择比较优先级
如果cpu中进程的优先级小,那么当前进程只会执行一半,我们算出他能够执行的时间,更新这个进程并且重新放回cpu中,并将即将进入的进程放进去
继续等待下一步处理,当前在q中的所有进程,都已经不用管开始时间了,因为如果在q中,就表明要么已经执行过,所以在门口等待执行,要么是即将执行,他们的bn(开始时间)都已经不存在什么意义,都已经是迫不及待等待了,所以q中的东西只用管优先级
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int id,bn,d,g;
};
//先比较进入时间的大小,如果时间冲突则比较优先级,但是题目给出的时间必然不相同
struct campareNode{
    bool operator() (const node &a,const node &b) const {
        if(a.g==b.g) return a.bn>b.bn;
        else return a.g<b.g;
    }
};
node c;
long long t;
priority_queue<node,vector<node>,campareNode> pq;
int main(){
    while(cin>>c.id>>c.bn>>c.d>>c.g){
        //当前的和堆的第一个对比
        while(!pq.empty()&&t+pq.top().d<=c.bn){//可以在这个t之前,那么先执行
            node ans = pq.top();
            cout<<ans.id<<" "<<t+ans.d<<endl;
            pq.pop();
            t += ans.d;
        }
        //执行了一半,更新进程时间,因为后面记录了时刻t,所以直接更新剩余操作时间
        if(!pq.empty()){
            node m = pq.top();
            pq.pop();
            m.d = m.d+t-c.bn;
            pq.push(m);
        }
        pq.push(c);
        t = c.bn;
    }
    //打印堆中剩余的数据
    while(!pq.empty()){
        node a = pq.top();pq.pop();
        cout<<a.id<<" "<<t+a.d<<endl;
        t += a.d;
    }
    return 0;
}