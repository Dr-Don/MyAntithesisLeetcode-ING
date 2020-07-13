/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /* 方法一：先把链表赋值到向量里再按照之前的方式处理 */
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        if(head == nullptr) return nullptr;
        ListNode* p = head;
        while(p){
            nums.push_back(p->val);
            p=p->next;
        }
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

};