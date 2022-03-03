/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        for(;columnNumber -- > 0;columnNumber /= 26)
        {
            ret += columnNumber % 26 + 'A';
        }
        return {ret.rbegin(), ret.rend()};
    }
};
// @lc code=end

