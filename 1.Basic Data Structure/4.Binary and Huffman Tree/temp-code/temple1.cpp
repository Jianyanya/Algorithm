//因为实在太简单,所以我直接自己出题了
//演示三种遍历:前序,中序,后序,使用动态创建的方法
#include <iostream>
using namespace std;
// 1. 定义节点结构
struct TreeNode {
    int val;
    TreeNode* left;//动态创建节点
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
静态数组
int N = 100100;
struct TreeNode {
    int val;
    int left,right;
}tree[N];
*/
// 2. 构建一棵树
TreeNode* buildSimpleTree() {
    //手动创建节点
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    // 像拼积木一样连接它们
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    return root; // 返回树的根节点
}
//前序遍历
void preorder(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
//中序遍历
void inorder(TreeNode* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
//后序遍历
void postorder(TreeNode* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    TreeNode *root = buildSimpleTree();
    // 测试遍历
    cout << "Preorder (前序): ";
    preorder(root);
    cout << endl;

    cout << "Inorder  (中序): ";
    inorder(root);
    cout << endl;

    cout << "Postorder(后序): ";
    postorder(root);
    cout << endl;
    return 0;
}