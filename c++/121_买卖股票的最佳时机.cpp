/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
注意：你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    /* 动态规划1
    本题要求的其实是卖出时与买入时的最大差值。我们不妨假设f(i)表示以第i天为结尾时卖出股票获得的最大收入（差值），
    那么最后要求的是：f(i) = max{f(i)| 1 <= i <= n>>};
    而f(i)其实还与f(i-1)有关，f(i-1) = p[i-1] - minValue, 
    其中minValue表示以i-1结尾的前排数组的最小值，故 minValue = p[i-1] - f(i-1)。
    那么我们可以得到如下关系： f(i) = max (p[i] - (p[i-1] - f(i-1), 0)) = max (f(i-1) + p[i] - p[i-1], 0); 
    （显然，每次可以当天买进，当天卖出，所以最大收益不应该低于0。
    */
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int maxVal = 0;
        int f1 = 0, f2 = 0;
        for(int i = 1; i < prices.size(); i++){
            f2 = max(f1 + prices[i] - prices[i-1], 0);
            maxVal = max(f2, maxVal);
            f1 = f2;
        }
        return maxVal;
    }

    /* 动态规划2 */
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for(int i = 0; i<n; i++){
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
    /* 使用到哨兵的单调栈 */
    int maxProfit(vector<int>& prices){
        int res = 0;
        vector<int> s;
        prices.emplace_back(-1); // 哨兵
        for(int i = 0; i < prices.size(); i++){
            while(!s.empty() && s.back() > prices[i]){ // 维护单调栈
                res = max(res, s.back() - s.front()); // 维护最大值
                s.pop_back();
            }
            s.emplace_back(prices[i]);
        }
        return res;
    }
};