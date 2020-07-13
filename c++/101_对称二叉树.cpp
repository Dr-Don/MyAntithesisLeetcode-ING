/*给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。*/

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

/*递归*/
bool leftnright(TreeNode* left,TreeNode* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    if(left->val == right->val){
        return leftnright(left->left,right->right) && leftnright(left->right,right->left);
    }
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return leftnright(root->left,root->right);  
}

/*迭代*/
bool isSymmetric(TreeNode* root){
    queue<TreeNode*> q = new queue<TreeNode>;
    q.push(root);
    q.push(root);
    while(!q.empty()){
        TreeNode* t1 = q.front();
        q.pop();
        TreeNode* t2 = q.front();
        q.pop();
        if(t1 == NULL && t2 == NULL) continue;
        if(t1 == NULL || t2 == NULL) return false;
        if(t1->val != t2->val) return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}

int main(){
    return 0;
}