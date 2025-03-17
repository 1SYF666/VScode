/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0,buy = INT_MAX;

        for (int price: prices)
        {
            buy = min(buy,price);
            res = max(res,price - buy);
        }       
        return res;
    }
};
// @lc code=end

