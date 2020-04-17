/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

/*先排序然后双指针*/
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end()); // 排序
    int i, sum = nums[0] + nums[1] + nums[2], start, end;
    int dis = sum;
    for(i = 0;i<nums.size();i++){
        start = i + 1;
        end = nums.size()-1;
        while(start < end){
            sum = nums[start] + nums[i] + nums[end];
            // 利用排序的性质移动指针
            if(abs(sum - target) < abs(dis - target)) dis = sum;
            if(sum > target) end--;
            if(sum < target) start++;
            if(sum == target) return sum;
        }
    }
    return dis;
}

int main(){
    int num[] = {-1,2,1,-4};
    int target = 1;
    vector<int> nums(num,num+4);
    cout<<threeSumClosest(nums,target)<<endl;
    system("pause");
}