/*给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int len = 0;
    if(nums.size() == 0) return len;
    for(vector<int>::iterator itr = ++nums.begin(); itr != nums.end();itr++){
        if(*itr == *(itr-1)){
            itr = nums.erase(itr - 1);
        }
    }
    len = nums.size();
    return len;
}

int main(){
    int num[10] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums(num,num+10);
    cout<<"len:"<<removeDuplicates(nums)<<endl;
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    //system("pause");
}