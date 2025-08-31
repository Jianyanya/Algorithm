//堆-洛谷-p3378,题目链接<https://www.luogu.com.cn/problem/P3378>
//堆最重要的还是在于其二叉树结构,请务必手写一个堆,有助于理解
//堆的操作无疑就是删除和插入
/*
插入操作
插入操作是指向二叉堆中插入一个元素,要保证插入后也是一棵完全二叉树
最简单的方法就是,最下一层最右边的叶子之后插入,如果最下一层已满，就新增一层
插入之后可能会不满足堆性质？
上浮
向上调整:如果这个结点的权值大于它父亲的权值,就交换,重复此过程直到不满足或者到根
可以证明,插入之后向上调整后,没有其他结点会不满足堆性质
向上调整的时间复杂度是O(logn)的
代码
void up(int x) {
  while (x > 1 && h[x] > h[x / 2]) {//这个是最大堆,如果是最小堆就改成<号就行
    swap(h[x], h[x / 2]);//swap是交换两个元素
    x /= 2;
  }
}

删除操作
删除是指删除堆顶即二叉树的根节点,要保证删除后也是一棵完全二叉树
如果直接删除根节点,那么就会变为两个堆,很难再处理
所以正难则反,我们考虑插入的逆操作,既然根节点难删,那就把他变成叶子节点再删除
可是直接进行调整是比较困难的,所以一般都是直接把根节点与最后一个节点交换
但是交换后的节点不符合堆性质,所以...
下沉
我们交换完后,要把根节点那个不符合的往下去调整,直到符合
向下调整:在该结点的儿子中,找一个最大的,与该结点交换,重复此过程直到底层
可以证明,删除并向下调整后,没有其他结点不满足堆性质
时间复杂度O(logn)
代码
void down(){
    int i = 1;
    while(i*2<=n){//不超出数组长度(n)
        int son = i*2;//左儿子
        if(son+1<=n&&h[son+1]>h[son]) son++;//son+1<=n表示右儿子存在,比较右儿子跟左儿子谁大
        if(h[son]<=h[i]) break;
        swap(h[son],h[i]);
        i = son;
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int heap[N],len = 0;//len为堆长度
void push(int n) {//n为新元素,不是下标
    heap[++len] = n;
    int x = len;
  while (x > 1 && heap[x] < heap[x / 2]) {
    swap(heap[x], heap[x / 2]);
    x /= 2;
  }
}
void pop(){
    heap[1] = heap[len--];//根节点替换为最后一个节点,节点数减少
    int i = 1;
    while(i*2<=len){//不超出数组长度(n)
        int son = i*2;//左儿子
        if(son+1<=len&&heap[son+1]>heap[son]) son++;//son+1<=n表示右儿子存在,比较右儿子跟左儿子谁大
        if(heap[son]<=heap[i]) break;
        swap(heap[son],heap[i]);
        i = son;
    }
}
int main(){
    int n;cin>>n;
    while(n--){
        int m;cin>>m;
        if(m==1) {int x;cin>>x;push(x);}
        else if(m==2) cout<<heap[1];
        else pop();
    }
    return 0;
}
