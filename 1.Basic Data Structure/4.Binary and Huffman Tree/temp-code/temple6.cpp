//最直接的哈夫曼-poj-p3253,题目链接<http://poj.org/problem?id=3253>
//我们要清楚,哈夫曼最核心的知识点是他的贪心过程,就是为什么这样构建一个树,能让其带权路径和最小(越小的越远,越大的越近)可以自己数学证明
//题目就是说一个木板要求锯成给定大小的木板,费用跟木板长度有关,求最小费用
//都把要锯成的木板长度都告诉了,又不是分苹果的题(烤贪心和二分难度较大),这道题就是小ks
//为什么要据呢,既然给了据好的长度,那就直接拼呗
//还是构建哈夫曼树
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(n--){
        int m;cin>>m;
        pq.push(m);
    }
    int ans = 0;
    while(pq.size()>1){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        pq.push(a+b);
        ans += a+b;
    }
    cout<<ans;
    return 0;
}