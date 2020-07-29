/*
给定一个二叉树，返回它的中序 遍历。

示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /* 递归 */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res){
        if(root){
            if(root->left) helper(root->left, res);
            res.push_back(root->val);
            if(root->right) helper(root->right, res);
        }
    }

    /* 迭代 */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* rt = root;
        while(rt || !s.empty()){
            while(rt){
                s.push(rt);
                rt = rt->left;
            }
            rt = s.top();
            s.pop();
            res.push_back(rt->val);
            rt = rt->right;
        }
        return res;
    }
};