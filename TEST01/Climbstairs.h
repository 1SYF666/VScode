#include <vector>
#include <cstdint>
using namespace std;
/*
时间: 20250710 14:52
70. 爬楼梯
简单
提示
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

// 暴力法
/*
    只有两数元素 1 和 2，然后放入容量为 n 的背包，一共有多少种类
    （不考虑顺序，即 1 和 2 ，2 和 1 分别为一种）
*/
void Climbstairs_backtracking(vector<int> &nums, int k, int currentsum, int &count)
{
    if (currentsum > k)
        return;
    if (currentsum == k)
    {
        count++;
        return;
    }

    // 不考虑顺序
    for (int i = 0; i < nums.size(); i++)
    {
        Climbstairs_backtracking(nums, k, currentsum + nums[i], count);
    }
}

// 动态规划方法

int Climbstairs_dynamicprogramming(int n)
{
    vector<uint64_t> dp(n, 1);
    if (n == 1)
        return dp[n - 1];
    dp[1] = 2;
    if (n == 2)
    {
        return dp[n - 1];
    }
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

/*
时间: 20250710 15:42
322. 零钱兑换
中等
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
*/

// 暴力算法
void coinchange_backtracking(vector<int> nums, int amount, uint64_t currentsum, int64_t depth, int64_t &count)
{
    if (currentsum == amount)
    {
        count = min(count, depth);
        return;
    }
    if (currentsum > amount)
    {
        return;
    }

    // 上界剪枝：如果已经用的硬币数不比 best 少，就没必要继续
    if (depth > count)
        return;

    for (int i = 0; i < nums.size(); i++)
    {
        coinchange_backtracking(nums, amount, currentsum + nums[i], depth + 1, count);
    }
}

//
int coinchange_dynamicprogramming(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            if (dp[j - coins[i]] != INT32_MAX)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if (dp[amount] == INT32_MAX)
        return -1;
    return dp[amount];
}

/*
时间: 20250711 15:27
279. 完全平方数
中等
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/

// 暴力法
static void perfect_squre_backtracking(vector<int> &nums, int n, uint32_t currentsum, int depth, int &count)
{
    if (currentsum == n)
    {
        count = min(depth, count);
        return;
    }

    if (currentsum > n)
    {
        return;
    }
    if (depth >= count) // 剪纸操作
        return;

    for (int i = 0; i < nums.size(); i++)
    {
        perfect_squre_backtracking(nums, n, currentsum + nums[i], depth + 1, count);
    }
}

int numSquares_bt(int n)
{
    vector<int> nums;
    // 获取完全平方数
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
            nums.push_back(i * i);
    }
    int result = INT32_MAX;
    perfect_squre_backtracking(nums, n, 0, 0, result);
    return result;
}

// 动态规划
int numSquares_dynamicprogramming(int n)
{
    vector<int> nums;
    // 获取完全平方数
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
            nums.push_back(i * i);
    }
    vector<int> dp(n+1,INT32_MAX);
    dp[0] = 0;
    
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = nums[i];j<=n;j++)
        {
            if(dp[j-nums[i]]!=INT32_MAX)
            {
                dp[j] = min(dp[j],dp[j-nums[i]]+1);
            }
        }
    }

    return dp[n];
}
