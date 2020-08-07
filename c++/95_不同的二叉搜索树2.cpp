/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

提示：
0 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /* 方法一：递归, 我们定义 generateTrees(start, end) 函数表示当前值的集合为 [start,end]，
    返回序列 [start,end] 生成的所有可行的二叉搜索树。按照上文的思路，
    我们考虑枚举 [start,end] 中的值 ii 为当前二叉搜索树的根，
    那么序列划分为了 [start,i−1] 和[i+1,end] 两部分。

    
    我们递归调用这两部分，即 generateTrees(start, i - 1) 和 generateTrees(i + 1, end)*/

    vector<TreeNode*> helper(int start, int end){
        if(start > end) return { nullptr };
        vector<TreeNode*> trees;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);

            for(auto& leftitem:left){
                for(auto& rightitem:right){
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = leftitem;
                    currTree->right = rightitem;
                    trees.emplace_back(currTree);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return helper(1,n);
    }
};