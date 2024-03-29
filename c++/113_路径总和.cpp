﻿/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
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

/* DFS+回溯 */
class Solution {
	vector<vector<int>> res;
	vector<int> path;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if(root) dfs(root, sum);
		return res;
	}

	void dfs(TreeNode* root, int sum) {
		int num = sum - root->val;
		path.push_back(root->val);
		if (num == 0 && !root->left && !root->right) res.push_back(path);
		if (root->left) dfs(root->left, num);
		if (root->right) dfs(root->right, num);
		path.pop_back();
	}
};