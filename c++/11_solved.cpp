/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2.
输入：[1,8,6,2,5,4,8,3,7]
输出：49
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/*我的解法 有参考官方题解。。
因为一开始我写的是两头指针分别直接移动到底。。
结果应该是每次循环只移动其中一个指针
而且并不是指针和自己的相邻比较，而是两个指针进行比较*/
int maxArea1(vector<int>& height){
    if(height.size() == 2) return min(height[0],height[1]);
    int len = height.size()-1;
    int maxArea = 0;
    int i = 0,j = len;
    /*寻找更高的桶高度*/
    while(i < j){
        len = j-i;
        maxArea = max(maxArea,min(height[i],height[j]) * len);
        if(height[i] < height[j]) i++;
        else j--;
    }
    return maxArea;
}

/*官方题解 */
int maxArea2(vector<int>& height){
    int maxArea = 0,l = 0,r = height.size()-1;
    while(l<r){
        maxArea = max(maxArea,min(height[l],height[r]) * (r-1));
        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxArea;
}

int main(){
    int a[] = {1,3,2,5,25,24,5};
    vector<int> height(a,a+7);
    cout<<maxArea2(height)<<endl;
    //system("pause");
    return 0;
}