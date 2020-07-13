/*给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例:
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

指针从尾部向前
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1,p2 = n-1,p = m+n-1;
    while(p1 >= 0 && p2 >= 0){
        nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
    }
    if(p1 < 0){
        while(p2 >= 0){
            nums1[p--] = nums2[p2--];
        }
    }
}

int main(){
    int num1[6] = {0};
    int num2[3] = {1};
    vector<int> a(num1,num1+1);
    vector<int> b(num2,num2+1);
    int m = 0;
    int n = 1;
    merge(a, m, b, n);
    for(int i = 0;i<1;i++){
        cout<<a[i]<<" ";
    }
    //system("pause");
    return 0;
}