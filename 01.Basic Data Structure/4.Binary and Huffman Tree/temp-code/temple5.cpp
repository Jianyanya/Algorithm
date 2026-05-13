//哈夫曼编码-poj-1521,题目链接<http://poj.org/problem?id=1521>
//好不容易找到的,非常简单的一道哈夫曼编码题,主要考察哈夫曼编码的本质
//别看描述,都是废话,直接看input和output,就是给你一个字符串,求8bit的ASCII码存储和用哈夫曼编码存储各需要多少位,并看看压缩效率有多高.
/*
我们先要知道以下知识
1.字母在ASCII码表中本来就是8进制位,所以储存长度就为(字符串长度*8)
2.哈夫曼编码长度就是所有带权路径长度之和
3.压缩效率就是(ASCII长度/哈夫曼编码长度*100%)

怎么实现?
我们要用到优先队列这个东西,就是最小(最大)生成堆,就相当一个单调栈,但是你只需要无脑把数据放进去,他会自动对堆中的数据进行排序
在构建哈夫曼树的时候,字母出现频次为节点值,先让节点按照大小排序,再去挑小的两个合并到一起,再放回原来进行排序,继续挑最小..
可以发现,我们把数据拿出来又放回去,还要保证每次拿出来的都是最小值,肯定是每次拿放里面都进行了排序,所以优先队列出来了
那么接下来就好实现了
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
string str;
int main(){
    while(getline(cin,str)&&str!="END"){
        priority_queue<int,vector<int>,greater<int>> pq;
        //计算每种字符的频次
        sort(str.begin(),str.end());
        int n = 1;
        for(int i = 1;i<=str.length();i++){
            if(str[i]!=str[i-1]) pq.push(n),n=1;
            else n++;
        }
        int ans = 0;
        //开始模拟
        if(pq.size()==1) ans = str.length();
        while(pq.size()>1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            pq.push(a+b);
            ans += a+b;
        }
        pq.pop();
        int s = str.length()*8;
        printf("%d %d %.1lf\n",s,ans,(double)s/(double)ans);
    }
    return 0;
}
