#include <vector>
using namespace std;
/*
时间：20250722 18:31
六一儿童节到了，爸爸送给儿子一盒进口糖果，但是儿子吃糖没有节制，出于对孩子身体健康的考虑，同时也是为了让孩子提高学习，爸爸想出这样的办法:
爸爸:我在圆形餐盘的边缘，摆放了几堆糖果，现在你进行相邻两堆糖果的合并，每合并一次得到一个分值，这个分值为此次合并糖果的个数和，直至将这些糖果合并成一堆，将合并过程中的得分加起来最大(M)，
这样你就可以得到最大分值五分之一的糖果(当分值是奇数时向下取整)，否则你只能得到你的计算结果的十分之一的糖果。
*/

// 长桌合并糖果
int distribution_table(vector<int> &nums)
{
    int n = nums.size();
    // 前缀和,用于O(1)求区间和
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + nums[i];
    }
    auto rangeSum = [&](int l, int r)
    {
        return pre[r + 1] - pre[l];
    };

    // dp[i][j] == 合并区间[i,j]的最大得分
    // 初始化dp[i][i] = 0(单堆不需要合并，得分0)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 枚举长度 len 从 2 到 n
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            int best = 0;
            int total = rangeSum(i, j);

            // 枚举最后一次合并点 K:先合并[i...k] 和[k+1...j]
            // 然后再把这两堆合并，得分 = dp[i][k] + dp[k+1][j] + total
            for (int k = i; k < j; k++)
            {
                best = max(best, dp[i][k] + dp[k + 1][j] + total);
            }
            dp[i][j] = best;
        }
    }
    return dp[0][n - 1];
}

// 圆桌合并糖果
int distributioncandy_roundtable(vector<int> &nums, int n)
{
    return 0;
}
