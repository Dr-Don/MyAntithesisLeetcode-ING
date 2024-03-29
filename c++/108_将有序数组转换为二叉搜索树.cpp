/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
using namespace std;

Random rand = new Random();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return helper1(nums, 0, nums.size()-1);
    }

    /* 选择中间位置左边的数字为根节点 */
    TreeNode* helper1(vector<int>& nums, int left,int right){
        if(left > right) return nullptr;

        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper1(nums, left, mid-1);
        root->right = helper1(nums, mid + 1, right);
        return root;
    }

    /* 选择中间位置右边的数字为根节点 */
    TreeNode* helper2(vector<int>& nums, int left,int right){
        if(left > right) return nullptr;

        int mid = (left + right + 1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper2(nums, left, mid-1);
        root->right = helper2(nums, mid + 1, right);
        return root;
    }

    /* 选择中间位置两边的任意一个节点为根节点 */
    TreeNode* helper3(vector<int>& nums, int left,int right){
        if(left > right) return nullptr;

        int mid = (left + right + rand.nextInt(2))/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper3(nums, left, mid-1);
        root->right = helper3(nums, mid + 1, right);
        return root;
    }
};