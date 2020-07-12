/*给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）


例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

一般会涉及DFS
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(root == nullptr) return res;
    // 1. 定义工作树
    vector<TreeNode*> work;
    work.push_back(root);
    work.push_back(nullptr);
    int i = 0;
    // 2. DFS遍历
    while(i < work.size()){
      if(!work[i]){
        i++;
        if(i >= work.size()) break;
        work.push_back(nullptr); // 每一层以空节点分割
      }
      if(work[i] -> right) work.push_back(work[i]->right);
      if(work[i] -> left) work.push_back(work[i]->left);
      i++;
    }
    // 3. 回溯得解
    vector<int> tmp;
    int index = work.size()-1;
    while((index--) > 0){
      if(work[index]) tmp.push_back(work[index]->val);
      else{
        res.push_back(tmp);
        tmp.clear();
      }
    }
}