/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0,n = prices.size();

        for (int i = 0; i < n-1; ++i)
        {
            if (prices[i]<prices[i+1])
            {
                res += prices[i+1] - prices[i];
            }
        }
        return res;
    }
};
// @lc code=end

