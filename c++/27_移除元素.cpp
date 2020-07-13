/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且nums中的前两个元素均为2。你不需要考虑数组中超出新长度后面的元素。
用迭代器时间消耗和空间消耗都很大！！！*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int len = 0;
    if(nums.size() == 0) return len;
    for(int i = 0;i<nums.size();i++){
        if(nums[i] == val){
            nums.erase(nums.begin()+i);
            i--;
        }  
    }
    len = nums.size();
    return len;
}

int main(){
    int num[4] = {3,2,2,3};
    int val = 3;
    vector<int> nums(num,num+4);
    cout<<"len:"<<removeElement(nums, val)<<endl;
    //system("pause");
}