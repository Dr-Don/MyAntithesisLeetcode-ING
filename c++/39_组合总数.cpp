/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

链接：https://leetcode-cn.com/problems/combination-sum
*/

#include <iostream>
#include <vector>
using namespace std;

/*回溯+剪枝
目标对数组中的每个数使用减法*/

vector<int> candidates;
vector<vector<int>> res;
vector<int> path;

void DFS(int start,int target){
    // 1. target减完，达到终止条件一
    if(target == 0){
        res.push_back(path);
        return;
    }

    // 2. 用减法查找符合条件的树枝
    for(int i = start;i < candidates.size() && target - candidates[i] >= 0;i++){
        path.push_back(candidates[i]);  // 添加元素值
        DFS(i,target - candidates[i]); // 递归，目标值减去元素值
        path.pop_back();  // 每次回溯将最后一个加入的元素值删除
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 1. 排序
    std::sort(candidates.begin(),candidates.end());
    this->candidates = candidates;
    // 2. 使用回溯算法
    DFS(0,target);
    return res;
}