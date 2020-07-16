/*
����һ����������ԭ�ؽ���չ��Ϊһ��������

���磬����������
	1
   / \
  2   5
 / \   \
3   4   6
����չ��Ϊ��
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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	/* �ⷨһ���ҵ����������ұߵĽڵ���������ӹ��� */
	void flatten(TreeNode* root) {
		// 1. ������Ϊnull��ֱ�ӿ�����һ���ڵ�
		if (root != nullptr) {
			if (root->left == nullptr) root = root->right;
			else {
				// 2. �ҵ����������ұߵĽڵ�
				TreeNode* pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}
				// 3. ��ԭ�����������ӵ������������ұ߽ڵ�
				pre->right = root->right;
				// 4. �����������뵽�������ĵط�
				root->right = root->left;
				root->left = nullptr;
				root = root->right;
			}
		}
	}

	/* �ⷨ����������� */
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