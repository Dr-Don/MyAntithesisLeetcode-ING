/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

链接：https://leetcode-cn.com/problems/combination-sum-ii
*/

#include <iostream>
#include <vector>
using namespace std;

/*
回溯+剪枝
和39题类似，区别是不能包含重复元素，那么递归调用就得从下一位开始
*/

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
        if(i > start && candidates[i] == candidates[i-1]) continue; // 筛选掉重复元素
        path.push_back(candidates[i]);  // 添加元素值
        DFS(i + 1,target - candidates[i]); // 递归，目标值减去元素值，元素不可重复用，i+1
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