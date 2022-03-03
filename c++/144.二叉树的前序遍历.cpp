/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 迭代
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();
            res.push_back(p->val);
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return res;
    }
};
// @lc code=end

