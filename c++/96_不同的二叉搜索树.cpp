/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
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
    /* 方法一：动态规划 
    举例而言，创建以 33 为根、长度为 77 的不同二叉搜索树，整个序列是 [1, 2, 3, 4, 5, 6, 7]，
    我们需要从左子序列 [1, 2]构建左子树，从右子序列 [4, 5, 6, 7]构建右子树，然后将它们组合（即笛卡尔积）。
    对于这个例子，不同二叉搜索树的个数为 F(3, 7)。我们将 [1,2] 构建不同左子树的数量表示为 G(2)G(2), 
    从 [4, 5, 6, 7]构建不同右子树的数量表示为 G(4)，注意到 G(n)和序列的内容无关，只和序列的长度有关。
    于是，F(3,7)=G(2)⋅G(4)。 因此，我们可以得到以下公式：
    F(i,n)=G(i−1)⋅G(n−i)(2)

    将公式 (1)，(2)结合，可以得到 G(n)的递归表达式：
    G(n)= 
    i=1
    ∑  G(i−1)⋅G(n−i)(3)
    n

    至此，我们从小到大计算 GG 函数即可，因为 G(n)的值依赖于G(0)⋯G(n−1)
    */
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= i;j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }

    /* 方法二：卡塔兰数 */
    int numTrees(int n){
        long long c = 1;
        for(int i = 0; i < n; i++){
            c=c*2*(2*i+1)/(i+2);
        }
        return (int)c;
    }

    /* 方法三：递归 */
    int numTrees(int n){
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        return helper(n, dp);
    }

    int helper(int n, int *dp){
        if(dp[n] > 0) return dp[n];
        for(int i = 0;i < n;i++){
            dp[n] += helper(i,dp) * helper(n-i-1, dp);
        }
        return dp[n];
    }
};