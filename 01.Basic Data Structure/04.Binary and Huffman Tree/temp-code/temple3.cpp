//层序遍历-leetcode-p102
//队列做法
/*
可以发现,我们每个节点遍历后要暂存,而且再遍历时是从头开始,先进去的先遍历,符合先进先出,队列!
父节点进队,再父节点出队头的时候读取该节点的子节点入队尾,依次操作
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
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> arr;
        while(!q.empty()){
            vector<int> a;
            int n = q.size();
            //注意有个坑,因为在入队时队列长度会增加,先要固定遍历次数n
            for(int i = 0;i<n;i++){
                TreeNode* t = q.front();
                a.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                q.pop();
            }
            arr.push_back(a);
        }
        return arr;
    }
};