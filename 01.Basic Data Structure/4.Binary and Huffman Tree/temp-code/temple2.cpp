//层序遍历-leetcode-p102,题目链接<https://leetcode.cn/problems/binary-tree-level-order-traversal>
//层序遍历与之前都不一样,可以说层序遍历是bfs的基础和本质,非常重要
//层序遍历会用上队列的知识,我还给出另一种解法来帮助理解;
/*
滚动数组法(双数组实现层序遍历)
层序遍历顾名思义就是一层层的遍历,那么如何实现呢
我们以第一层为父层,先遍历父层,遍历完后父层还有用,要遍历父层的子节点,所以父层要暂存在一个数组中
遍历完后从头开始再次遍历父层数组,得到子层,并把子层暂存到一个数组中,以此类推遍历下面的
由于父层遍历完后就没用了,浪费了数组,所以可以在遍历完子层后让子层覆盖父层,即开销只需要两个数组
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};//特判
        vector<vector<int>> ans;
        vector<TreeNode*> cur = {root};//头节点先进
        while(cur.size()){//直到没有了
            vector<TreeNode*> next;
            vector<int> temp;
            for(TreeNode* node:cur){
                temp.push_back(node->val);
                //一定要记得先判断是否为空
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            cur = move(next);//把next移动给cur,然后删除next,此题的关键优化点
            ans.push_back(temp);
        }
        return ans;
    }
};