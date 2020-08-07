/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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

class Solution {
public:
    /* 方法一：BFS */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLevelSize = q.size();
            res.push_back(vector<int>());
            for(int i = 1;i <= currentLevelSize;++i){
                auto node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }

    /* 方法二：递归 */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        dfs(1, root, res);
        return res;
    }

    void dfs(int index, TreeNode* root, vector<vector<int>> &res){
        if(res.size() < index) res.push_back(vector<int>());
        res[index-1].push_back(root->val);
        if(root->left) dfs(index + 1,root->left,res);
        if(root->right) dfs(index + 1,root->right,res);
    }
};