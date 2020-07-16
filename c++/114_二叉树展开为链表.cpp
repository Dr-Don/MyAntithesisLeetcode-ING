/*
给定一个二叉树，原地将它展开为一个单链表。

例如，给定二叉树
	1
   / \
  2   5
 / \   \
3   4   6
将其展开为：
1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	/* 解法一：找到左子树最右边的节点把右子树接过来 */
	void flatten(TreeNode* root) {
		// 1. 左子树为null，直接考虑下一个节点
		if (root != nullptr) {
			if (root->left == nullptr) root = root->right;
			else {
				// 2. 找到左子树最右边的节点
				TreeNode* pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}
				// 3. 将原来的右子树接到左子树的最右边节点
				pre->right = root->right;
				// 4. 将左子树插入到右子树的地方
				root->right = root->left;
				root->left = nullptr;
				root = root->right;
			}
		}
	}

	/* 解法二：后序遍历 */
	TreeNode* pre = nullptr;

	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		flatten(root->right);
		flatten(root->left);
		root->right = pre;
		root->left = nullptr;
		pre = root;
	}
};