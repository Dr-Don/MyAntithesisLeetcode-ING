/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/* 方法一：BFS */
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		queue<TreeNode*> nodes;
		queue<int> val;
		nodes.push(root);
		val.push(root->val);
		while (nodes.empty()) {
			TreeNode* now = nodes.front();
			int temp = val.front();
			nodes.pop();
			val.pop();
			if (now->left == nullptr && now->right == nullptr) {
				if (temp == sum) return true;
				continue;
			}
			if (now->left) {
				nodes.push(now->left);
				val.push(now->left->val + temp);
			}
			if (now->right) {
				nodes.push(now->right);
				val.push(now->right->val + temp);
			}
		}
		return false;
	}

	/* 方法二：DFS递归 */
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		if (root->left == nullptr && root->right == nullptr) return sum == root->val;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};