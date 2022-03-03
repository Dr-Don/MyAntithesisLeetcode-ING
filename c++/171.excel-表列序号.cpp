/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        for(int i = 0;i < columnTitle.size();++i)
        {
            ret = ret*26 + (columnTitle[i] - 'A' + 1);
        }
        return ret;
    }
};
// @lc code=end

