/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

示例:
输入: 3
输出: [1,3,3,1]
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int> (1,1);
        if(rowIndex == 1) return vector<int> (2,1);
        vector<int> res(rowIndex+1, 1);
        vector<int> last = getRow(rowIndex - 1);
        for(int i = 1; i < rowIndex; i++){
            res[i] = last[i-1] + last[i]; 
        } 
        return res;
    }
};