/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:
输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]
   3
  /
 1
  \
   2

示例 2:
输入: [3,1,4,null,null,2]
  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]
  2
 / \
1   4
   /
  3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /* 方法一：迭代中序遍历 */
    void swap(TreeNode* a, TreeNode* b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *x,*y,*pred;
        while(!s.empty() || root){
            while(root){
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pred && root->val < pred->val){
                y = root;
                if(x == nullptr) x = pred;
                else break;
            }
            pred = root;
            root = root->right;
        }
        swap(x,y);
    }

    /* 方法二：递归中序遍历 */


};