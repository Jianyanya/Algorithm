//二叉树遍历-hdu-p1710,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=1710>
//弄清楚前序中序后序之间的联系,再遍历就很简单了,涉及递归和分治
/*
关系:
前序遍历: 根->左子树->右子树
中序遍历: 左子树->根->右子树
后序遍历: 左子树->右子树->根
我们要单独处理树的左支和右支,所以必然要找到一个根节点将其分开,若只知道后序和前序,不就没法确定根和分支的关系了吗
我们可以发现,在前序遍历中,第一个元素一定是根,在中序遍历中找到对应根,就是把树一分为二的地方,找到后再单独处理左子树和右子树

找到关系后怎么确定后序遍历
这个过程就是递归地处理每一个子树
1.从前序遍历中找到当前子树的根(总是第一个节点)
2.在中序遍历中找到这个根,从而确定左子树和右子树分别包含哪些节点
3.对左子树和右子树分别重复步骤1和2(这是一个递归过程)
4.在递归处理完左右子树之后,最后"访问"根节点也就是把它放入后序遍历的结果中)
在访问的时候就已经形成后序遍历了

怎么实现呢?
我们假设有
前序遍历: [A,B,D,E,C,F,G]
中序遍历: [D,B,E,A,F,C,G]
1.定位前序中的第一个根A
2.划分中序,在中序中找到A,A的左边[D,B,E]是左子树的中序,右边[F,C,G]是右子树的中序
3.划分前序,找到左右子树后就可以得到两个子问题
    左子树:前序 = [B,D,E],中序 = [D,B,E],求其后序
    右子树:前序 = [C,F,G],中序 = [F,C,G],求其后序
4.递归处理并和并答案,继续处理上述子树,将其视为单独的树再思考,可分为
    左子树: 根为B,其左子树为D,其右子树为E,后序为[D,E,B]
    右子树: 根为C,其左子树为F,其右子树为G,后序为[F,G,C]
5.合并答案[D,E,B]+[F,G,C]+[A],即为答案

那对于后序遍历+中序遍历呢;
同理,只是顺序不一样罢了,我们可以把后序遍历拿出来:左子树->右子树->根
我们从后面开始遍历,先找到根,这里由于先找右子树,所以在分治的时候也要从中序遍历的右边开始找
分治的思路一模一样,代码中有几个小细节要注意
1. 输出节点的时候要在遍历左子树和右子树前,其实就是要保证
    cout
    左子树
    右子树
2. 有人可能会认为要先找右子树所以先遍历右子树,这个结构是不行的,因为和输出绑定了,这样会导致输出顺序错误
*/
//练习<https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805065406070784&page=1>
#include<iostream>
#include<vector>
using namespace std;
void fezh(int preleft,int preright,int inleft,int inright,vector<int> &pre,vector<int> &in){
    if(preleft>preright||inleft>inright) return;//递归结束
    int n = pre[preleft];//第一个根
    int it = inleft;//从中序中查找到的根
    //为了防止节点的值相同,所以用线性搜索,如果保证每个节点都不相同则使用map存储键值对
    for (; it <= inright; it++) {
        if (in[it] == n) break;
    }
    int sizes = it-inleft;//计算左子树长度
    fezh(preleft+1,preleft+sizes,inleft,it-1,pre,in);//左子树
    fezh(preleft+sizes+1,preright,it+1,inright,pre,in);//右子树
    cout<<n<<" ";//遍历节点
}
int main(){
    int n;
    while(cin>>n){
    vector<int> pre(n);
    vector<int> in(n);
    for(int i = 0;i<n;i++) cin>>pre[i];
    for(int i = 0;i<n;i++) cin>>in[i];
    fezh(0,n-1,0,n-1,pre,in);
    cout<<endl;
    }
    return 0;
}