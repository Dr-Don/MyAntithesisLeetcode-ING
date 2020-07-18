/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
实例:
输入: 5
输出:
[
	 [1],
	[1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		for (int i = 0; i < numRows; ++i) {
			res[i].resize(i+1,1);
			for(int j = 1; j < i; j++){
				res[i][j] = res[i-1][j-1] + res[i-1][j];
			}
		}
		return res;
	}
};