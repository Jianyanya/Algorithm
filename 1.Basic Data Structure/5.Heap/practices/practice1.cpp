//操作系统-洛谷-p2278,题目链接<https://www.luogu.com.cn/problem/P2278>
//
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
        while(!pq.empty()&&t+pq.top().d<=c.bn){
            node ans = pq.top();
            cout<<ans.id<<" "<<t+ans.d<<endl;
            pq.pop();
            t += ans.d;
        }
        if(!pq.empty()){
            node m = pq.top();
            pq.pop();
            m.d = m.d+t-c.bn;
            pq.push(m);
        }
        pq.push(c);
        t = c.bn;
    }
    while(!pq.empty()){
        node a = pq.top();pq.pop();
        cout<<a.id<<" "<<t+a.d<<endl;
        t += a.d;
    }
    return 0;
}