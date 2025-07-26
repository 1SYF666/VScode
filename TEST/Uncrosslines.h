#include <vector>
#include <string>
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

/*
时间：20250726 11:01
72. 编辑距离
中等
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/
int minDistance_72dp(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // dp[i][j] 表示 [0,i-1]A和转换为[0,j-1]B 所使用的最小操作数
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i; // 删除字符
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j; // 插入字符
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int temp1 = dp[i - 2][j] + 1;     // 插入一个字符
                int temp2 = dp[i - 1][j] + 1;     // 删除一个字符
                int temp3 = dp[i-1][j-1] + 1; // 替换一个字符
                dp[i][j] = min(min(temp1, temp2), temp3);
            }
        }
    }
    return dp[n][m];
}