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
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 注意这里是和121. 买卖股票的最佳时机唯一不同的地方。
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

/*
时间：20250715 14:29
123. 买卖股票的最佳时机 III
困难
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

// 通过率：149/241
int maxprofit3_bf(vector<int> &prices)
{
    if (prices.size() == 1)
        return 0;
    vector<int> diff(prices.size() - 1, 0);
    vector<int> temp;
    int flag1 = 0; // 全是正数
    int flag2 = 0; // 全是负数
    for (int i = 1; i < prices.size(); i++)
    {
        diff[i - 1] = prices[i] - prices[i - 1];
        if (diff[i - 1] < 0)
        {
            flag1 = 1;
        }
        if (diff[i - 1] > 0)
        {
            flag2 = 1;
            temp.push_back(diff[i - 1]);
        }
    }
    if (!flag1 && flag2)
    {
        // 全是正数
        return prices[prices.size() - 1] - prices[0];
    }
    else if (!flag2 && flag1)
    {
        // 全是负数
        return 0;
    }
    else if (flag1 && flag2)
    {
        // 有正数和负数
        int result = 0;
        if (temp.size() == 1)
        {
            return temp[0];
        }
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = i + 1; j < temp.size(); j++)
            {
                result = max(result, temp[i] + temp[j]);
            }
        }
        return result;
    }
    return 0;
}
// 通过率： 201 / 214 -- 超时 
int maxprofit3_bf2(vector<int> &prices)
{
    int len = prices.size();
    int sum = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            sum1 = prices[j] - prices[i];

            sum2 = 0;
            for (int k = j + 1; k < len; k++)
            {
                for (int z = k + 1; z < len; z++)
                {
                    sum2 = max(sum2, prices[z] - prices[k]);
                }
            }
            sum = max(sum, sum1 + sum2);
        }
    }
    return sum;
}
