/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
*/

#include <iostream>
#include <vector>
using namespace std;

/*回溯算法*/
void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
  // 1. 添加子串，设置终止条件
  if(first == len){
    res.emplace_back(output);
    return;
  }
  for(int i = first;i < len; i++){
    // 2. 动态维护数组
    std::swap(output[i], output[first]);
    // 3. 继续递归听下一个数
    backtrack(res, output, first+1, len);
    // 4. 撤销，返回上一个状态,这一步有点妙
    std::swap(output[i], output[first]);
  }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}

int main(){

}