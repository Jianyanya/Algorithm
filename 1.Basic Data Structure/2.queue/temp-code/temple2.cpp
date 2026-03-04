//洛谷p1540-手写循环队列
//首先我来解决你的第一个疑惑,为什么是循环队列,一般队列的代码呢?弄错顺序了吗?
//实则不然,其实我们一般看到的队列实现都是循环队列,因为一般队列会出现"假溢出"的现象
//什么是假溢出?
// 初始状态：[_ _ _ _ _]
// front=0, rear=-1(front代表队头下标,rear代表队尾下标,这里-1代表没用数据)

// 入队5次：[1 2 3 4 5]
// front=0, rear=4

// 出队2次：[x x 3 4 5]
// front=2, rear=4

// 此时虽然前面有空间，但无法再入队！
// 这就是"假溢出"
//如果你从来没有自己手搓过数据结构,你大概率是不知道这个的
//那么出现这种现象的关键就在于head和rear这两个节点的数值,没办法再回到队列的头部
// 初始：[1 2 3 4 5] front=0, rear=4
// 出队2次：[x x 3 4 5] front=2, rear=4

// 再入队：rear = (4 + 1) % 5 = 0
// 在位置0放入6：[6 x 3 4 5] front=2, rear=0 成功！

// 再入队：rear = (0 + 1) % 5 = 1  
// 在位置1放入7：[6 7 3 4 5] front=2, rear=1 成功！

//所以使用取模的技巧来实现这一操作
//依旧官方标准写法,动态分配内存
//手搓数据结构,我真的要炸了,学数据结构的时候写了一遍,现在又要写
//麻烦也要坚持,脚踏实地的努力,相信你一定要自己也要写一遍,这不是浪费时间,而是在压实你的能力
//我真不想写T-T
#include<bits/stdc++.h>
using namespace std;
int arr[1001] = {0};
struct myqueue{
    int *data;//分配动态空间
    int head,rear;//队头队尾
    int len;//初始化长度(分配给的空间)
    int sizes;//我在做的时候发现最好还是定义一个sizes来记录队列长度
    bool init(int n){
        len = n;
        data = (int*)malloc(n*sizeof(int));//看到malloc你应该很熟悉
        if(!data) return false;
        head = rear = sizes = 0;//初始化
        return true;
    }
    int size(){
        return sizes;
    }
    bool empty(){
        return head==rear;
    }
    int front(){
        return data[head];
    }
    bool push(int n){
        if(sizes==len) return false;
        sizes++;
        data[rear] = n;
        rear = (rear+1)%len;//循环队列的关键实现
        return true;
    }
    bool pop(){//原本是void,但我们可以改成bool,以方便检验是否出队成功
        if(head==rear) return false;
        head = (head+1)%len;
        sizes--;
        return true;
    }
    int back(){
        return data[rear];
    }
}Q;
int main(){
    int M,N;cin>>M>>N;
    Q.init(M+1);
    int ans = 0;
    while(N--){
        int m;cin>>m;
        if(arr[m]==0){
            arr[m]++;
            ans++;
            if(Q.size()>=M){
                int t = Q.front();
                arr[t]--;
                Q.pop();
            }
            Q.push(m);
        }
    }
    cout<<ans;
    return 0;
}