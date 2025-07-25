#include <vector>
using namespace std;
/*
时间:20250724 15:10
1035. 不相交的线
中等
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。以这种方法绘制线条，并返回可以绘制的最大连线数。
*/
// 通过率54/74
static void maxUncrossedLines_backtracking(int x, int y, int cnt, vector<int> &A, vector<int> &B, int &best)
{
    int n = A.size();
    int m = B.size();
    best = max(best, cnt);
    if (x >= n || y >= m)
        return;

    for (int i = x; i < n; i++)
    {
        for (int j = y; j < m; j++)
        {
            if (A[i] == B[j])
            {
                maxUncrossedLines_backtracking(i + 1, j + 1, cnt + 1, A, B, best);
            }
        }
    }
}

int maxUncrossedLines_bf(vector<int> &nums1, vector<int> &nums2)
{
    int result = 0;
    maxUncrossedLines_backtracking(0, 0, 0, nums1, nums2, result);
    return result;
}

// 动态规划 -- 最长公共子序列
int maxUncrossedLines_dp(vector<int> &nums1, vector<int> &nums2)
{
    // dp[i][j] 表示 [0,i-1]的 A 和 [0,j-1]的 B 最长公共子序列的长度

    int n1 = nums1.size();
    int n2 = nums2.size();
    if (!n1 || !n2)
        return 0;
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}
