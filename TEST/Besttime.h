#include <vector>
using namespace std;
/*
时间：20250715 9:49
121. 买卖股票的最佳时机
简单
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0。
*/

// 暴力法
int maxprofit_bf(vector<int> &price)
{

    int result = 0;
    for (int i = 0; i < price.size(); i++)
    {
        // 第i天买入
        for (int j = i + 1; j < price.size(); j++)
        {
            // 第j天卖出
            result = max(result, price[j] - price[i]);
        }
    }
    return result;
}
// 贪心算法
int maxprofit_greedy(vector<int> &price)
{
    int low = __INT_MAX__;
    int result = 0;
    for (int i = 0; i < price.size(); i++)
    {
        low = min(low, price[i]);             // 取最左最小价格
        result = max(result, price[i] - low); // 直接取最大区间利润
    }
    return result;
}

// 动态规划
int maxprofit_dp(vector<int> &prices)
{
    int len = prices.size();
    if (len == 0)
        return 0;

    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++)
    {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

/*
时间：20250715 10:57
122. 买卖股票的最佳时机 II
中等
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
*/

int maxprofit2_bf(vector<int> &prices)
{
    int sum = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] >= 0)
            sum += prices[i] - prices[i - 1];
    }
    return sum;
}

// 动态规划
int maxprofit2_dp(vector<int> &prices)
{
    int len = prices.size();
    if (len == 0)
        return 0;

    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);  // 注意这里是和121. 买卖股票的最佳时机唯一不同的地方。
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}