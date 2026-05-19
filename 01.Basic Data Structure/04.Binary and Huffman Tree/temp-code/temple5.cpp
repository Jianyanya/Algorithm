//https://www.luogu.com.cn/problem/P1229
/*
做完了知道前序或者后序 + 中序遍历可以构建一颗二叉树
现在我们来看,求知道前序和后序之后,能构造的二叉树树有多少种
还是看前序和后序的构成
前序遍历: 根 -> 左子树 -> 右子树
后序遍历: 左子树 -> 右子树 -> 根
依旧是从根开始,我们可以先记录前序中根在后序中出现的位置
然后还是分治和递归的方法
我们可以想象前序和后序就是一条线,一个从前往后找,一个从后往前找,然后相遇或不相遇
因此我们分为两种情况来讨论
1. 当我们记录的两个根出现的位置相同时(相遇)
前面和后面都相遇了,那不就确定了一颗树吗,只是不知道左树还是右树,都行,因此返回2倍的结果
因为我们是按顺序从前序遍历中找的,所以判断i == sufR - 1;sufR为后序右端点
2. 不相遇的情况
这时就会遇到以下情况
(遍历过的点) + 根(当前遍历到的点) + (填充物) + 后面的点
(遍历过的点) + (填充物) + 根(当前遍历到的点) + (填充物) + (遍历过的点)
这里两个根就被分为左右子树了,所以已经确定了,那么就继续在左右搜索
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string pre,suf;
    cin>>pre>>suf;
    int n = pre.size();
    unordered_map<char,int> mp;
    for (int i = 0; i < n; ++i) {
        mp[suf[i]] = i;
    }
    auto dfs = [&](this auto&& dfs,int prel,int prer,int sufl,int sufr) -> ll {
        if(prel >= prer || sufl >= sufr) return 1;
        int pos = mp[pre[prel]];
        if(pos == sufr - 1){
            return 2*dfs(prel + 1,prer,sufl,sufr - 1);
        }else{
            int size = pos - sufl + 1;
            int left = dfs(prel + 1,prel + size,sufl,pos);
            int right = dfs(prel + size + 1,prer,pos + 1,sufr - 1);
            return 1LL*left*right;
        }
        
    };
    cout<<dfs(0,n - 1,0,n - 1)<<endl;
    return 0;
}