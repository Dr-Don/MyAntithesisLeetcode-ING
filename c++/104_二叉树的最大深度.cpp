/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。。*/

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*方法一：递归*/
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right) + 1;
}

/*方法二：DFS*/
int DFS(TreeNode* root,int depth){
    if(root == NULL) return depth;
    int left = DFS(root->left,depth+1);
    int right = DFS(root->right,depth+1);
    return max(left,right);
}

int maxDepth(TreeNode* root) {
    int depth = 0;
    return DFS(root,depth);


}