#include <vector>
#include <algorithm>
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

// 动态规划
int maxprofit3_dp(vector<int> &prices)
{
    // 0 不操作
    // 1 第一次持有
    // 2 第一次不持有
    // 3 第二次持有
    // 4 第二次不持有
    int row = prices.size();
    vector<vector<int>> dp(row, vector<int>(5, 0));

    // 初始化
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);

        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[row - 1][4];
}

/*
时间：20250717 10:57
188. 买卖股票的最佳时机 IV
困难
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/
// 通过率：192/210  -- 只计算k = 1 和 2 的情况
int maxProfit4_bf1(int k, vector<int> &prices)
{
    if (k <= 2)
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
    else
    {
        return 0;
    }
}
// 通过率：199/210
int maxProfit4_bf2(int k, vector<int> &prices)
{
    if (prices.size() <= 1)
    {
        return 0;
    }
    vector<int> diff(prices.size() - 1, 0);
    int count = 0;
    int index = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        diff[i - 1] = prices[i] - prices[i - 1];
    }
    vector<int> temp(diff.size(), 0);
    temp[0] = diff[0];
    for (int i = 1; i < diff.size(); i++)
    {

        if (diff[i] < 0 && diff[i - 1] >= 0)
        {
            temp[++index] = diff[i];
        }
        else if (diff[i] < 0 && diff[i - 1] < 0)
        {
            temp[index] += diff[i];
        }
        else if (diff[i] >= 0 && diff[i - 1] >= 0)
        {
            temp[index] += diff[i];
        }
        else if (diff[i] >= 0 && diff[i - 1] < 0)
        {
            temp[++index] = diff[i];
        }
    }

    sort(temp.begin(), temp.end());
    int sum = 0;
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        if (temp[i] > 0 && count < k)
        {
            count++;
            sum += temp[i];
        }
    }
    return sum;
}

// 动态规划
int maxProfit4_dp(int k, vector<int> &prices)
{
    // 0 不操作
    // 1 第一次持有
    // 2 第一次不持有
    // 3 第二次持有
    // 4 第二次不持有
    // ...
    int row = prices.size();
    int col = 2 * k + 1;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 1; i < col; i = i + 2)
    {
        dp[0][i] = -prices[0];
    }

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0];
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        // dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        // dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        // dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        for (int j = 1; j < col; j++)
        {
            if (j % 2 == 1) // 奇数
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }
            else // 偶数
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
    }
    return dp[row - 1][col - 1];
}

/*
时间：20250717 13:54
309. 买卖股票的最佳时机含冷冻期
中等
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

// 动态规划
int maxProfit5_dp(vector<int> &prices)
{
    // 0 持有
    // 1 不持有
    int row = prices.size();
    vector<vector<int>> dp(row, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < row; i++)
    {
        if (i == 1)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
    }
    return dp[row - 1][1];
}

/*
时间：20250722 14:20
714. 买卖股票的最佳时机含手续费
中等
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/

int maxProfit6_dp(vector<int> &prices, int fee)
{
    int row = prices.size();
    // 0 表示 持有 股票 所得最大金额
    // 1 表示 不持有 股票 所得最大金额
    vector<vector<int>> dp(row, vector<int>(2, 0));

    // 初始化
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp[row - 1][1];
}