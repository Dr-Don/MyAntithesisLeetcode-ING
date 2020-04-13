/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int res = 0;
    int i;
    for(i = 0;i < nums.size();i++){
        if(nums[i] == target){
            return i;
        }
        else if(nums[i] > target){
            if(i == 0) return i;
            if(nums[i - 1] < target) return i;
        }
    } 
    return nums.size();
}

int main(){
    int num[4] = {1,3,5,6};
    vector<int> nums(num,num+4);
    cout<<searchInsert(nums,7)<<endl;
    //system("pause");
    return 0;
}