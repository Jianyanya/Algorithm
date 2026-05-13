//机器翻译-洛谷-p1540,题目链接<https://www.luogu.com.cn/problem/P1540>
//主要介绍stl库中的queue
//队列只记住先进先出,后进后出,相比链表队列的操作就简单多了
/*
queue<Type> q;
q.pop(),弹出队首元素
q.push(),入队(从后面)
q.front(),返回队首元素(不出队)
q.bcak(),返回队尾元素
q.size(),长度
q.empty(),是否为空
*/
//这题还用了个哈希算法,说的高级,就是利用数组下标查找
//当数组下标对应值不为0时,说明出现过这个元素,还可以记录出现次数呢
//但是当数据大的时候,数组就不行了,得用哈希表记录;
#include<bits/stdc++.h>
using namespace std;
vector<int> arr(1001,0);//数组下标记录
queue<int> q;
int main(){
    int M,N;cin>>M>>N;
    int ans = 0;
    while(N--){
        int n;cin>>n;
        if(arr[n]==0){//没出现过
            arr[n]++;//现在出现了
            ans++;//记录答案
             if(q.size()>=M){//队列中元素数量大于指定值
                int m = q.front();//获得队首元素
                q.pop();//出队
                arr[m]--;//这个元素出去了,所以又不在了
            }
            q.push(n);//入队
        }
    }
    cout<<ans;
    return 0;
}