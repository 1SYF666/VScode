#include <vector>
using namespace std;

/*
时间: 20250706 14:20
背包最大重量为4，物品为：
            重量	价值
物品0	    1	    15
物品1	    3	    20
物品2	    4	    30
每件商品都有无限个！
问背包能背的物品最大价值是多少？
*/

void backtracking_exp1(const vector<int> &weight, const vector<int> value, const int maxweight, int currentweight, int currentvlaue, int &maxvalue)
{
    // 终止条件
    if (currentweight > maxweight)
    {
        return;
    }
    maxvalue = max(currentvlaue, maxvalue);
    // 可以无限使用
    for (int i = 0; i < weight.size(); i++)
    {
        backtracking_exp1(weight, value, maxweight, currentweight + weight[i], currentvlaue + value[i], maxvalue);
    }
}

int DynamicProgramming_exp1(const vector<int> &weight, const vector<int> value, int n, const int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    // 初始化
    for (int j = 1; j <= maxweight; j++)
    {
        dp[0][j] = j / weight[0] * value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= maxweight; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
        }
    }
    return dp[n - 1][maxweight];
}

/*
518. 零钱兑换 II
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。
题目数据保证结果符合 32 位带符号整数
*/

// 动态规划
#include <cstdint>
int DynamicProgramming_exp2(const vector<int> &coins, const int amount)
{
    vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, 0));

    // 初始化
    for (int j = coins[0]; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }

    // 初始化最左列
    for (int i = 0; i < coins.size(); i++)
    {
        dp[i][0] = 1;
    }

    // 开始遍历
    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coins[i])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[coins.size() - 1][amount];
}

// 暴力求解法

int backtracking_exp2(const vector<int> &coins, int amount, int index)
{
    if (amount == 0)
        return 1;
    if (amount < 0 || index >= coins.size())
        return 0;

    // 不使用当前硬币
    int waysWithout = backtracking_exp2(coins, amount, index + 1);
    // 使用当前硬币
    int waysWith = backtracking_exp2(coins, amount - coins[index], index);

    return waysWith + waysWithout;
}

/*
时间：20250709 14:24
377. 组合总和 Ⅳ
中等
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。
*/

// 暴力求解
int backtracking_exp3(vector<int> &nums, int target, int currentsum, int index)
{
    // 不重复（1 1 2）和（2 1 1） 是一类 不考虑顺序
    if (currentsum > target || index >= nums.size())
    {
        return 0;
    }
    if (currentsum == target)
    {
        return 1;
    }
    // 不选择当前
    int without = backtracking_exp3(nums, target, currentsum, index + 1);
    // 选择当前
    int with = backtracking_exp3(nums, target, currentsum + nums[index], index);

    return with + without;
}

void backtracking_exp4(vector<int> &nums, int target, int currentsum, int &count)
{
    // 重复,（1 1 2）和（2 1 1） 是两类 考虑顺序
    if (currentsum > target)
    {
        return;
    }
    if (currentsum == target)
    {
        count++;
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        backtracking_exp4(nums, target, currentsum + nums[i], count);
    }

    return;
}

// 动态规划

int DynamicProgramming_exp3(vector<int> &numns, int target)
{
    vector<uint64_t> dp(target + 1, 0);
    dp[0] = 1;
    // 开始遍历
    for (int i = 0; i <= target; i++)
    {
        for (int j = 0; j < numns.size(); j++)
        {
            if(i-numns[j]>=0)
                dp[i]+=dp[i-numns[j]];
        }
    }
    return dp[target];
}
