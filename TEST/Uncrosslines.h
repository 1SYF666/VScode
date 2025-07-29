#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
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
                int temp1 = dp[i][j - 1] + 1;     // 插入一个字符 -- 相当于 word2增加一个字符a ,然后word1和word2删除a进行比较。
                int temp2 = dp[i - 1][j] + 1;     // 删除一个字符
                int temp3 = dp[i - 1][j - 1] + 1; // 替换一个字符
                dp[i][j] = min(min(temp1, temp2), temp3);
            }
        }
    }
    return dp[n][m];
}

/*
时间：20250727 14:39
560. 和为 K 的子数组
中等
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
子数组是数组中元素的连续非空序列。
*/
/*
回溯（DFS）是枚举「可选可不选」的场景（比如子序列、组合、拆分等），需要在每个元素上做“选/不选”分支。
子数组要求“起点固定后，只能向右连续取”，没有“不选”那条分支，
所以只要双层 for‐loop，就能一次性把所有连续区间都覆盖到，代码简单效率也更高O(n^2)。
*/

// 获取数组的子数组 -- 两层for--loop
vector<vector<int>> getsubarray(vector<int> &nums)
{
    vector<int> subarray;
    vector<vector<int>> path;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            subarray.push_back(nums[j]);
            path.push_back(subarray);
        }
        subarray.clear();
    }
    return path;
}

int subarraySum_bfv2(vector<int> &nums, int k)
{
    vector<int> subarray;
    vector<vector<int>> path;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            subarray.push_back(nums[j]);
            if (sum == k)
                path.push_back(subarray);
        }
        subarray.clear();
    }

    for (int i = 0; i < path.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < path[i].size(); j++)
        {
            cout << path[i][j] << (j + 1 < path[i].size() ? ", " : "");
        }
        cout << "]" << endl;
    }
    return path.size();
}

// 通过率：86 / 93
auto rangesum(int i, int j, vector<int> &pre)
{
    return pre[j + 1] - pre[i];
}
int subarraySum_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    // 前缀和
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    int count = 0;
    //
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (rangesum(i, j, pre) == k)
                count++;
        }
    }
    return count;
}

int subarraySum_optimise(vector<int> &nums, int k)
{
    int count = 0;
    // 前缀和
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    // pre[i] 表示[0,i-1]数组的和
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }

    unordered_map<int, int> temp;
    for (int i = 0; i <= n; i++)
    {
        if (temp.count(pre[i] - k))
        {
            count += temp[pre[i] - k];
        }
        ++temp[pre[i]];
    }
    return count;
}

/*
647. 回文子串
中等
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
*/
// 通过率：132/132
static bool ispalindromic(string s)
{
    int n = s.size();
    int left = 0;
    int right = n - 1;
    // AAbAA
    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int countSubstrings_bf(string s)
{
    int n = s.size();
    int cnt = 0;
    string temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            temp.push_back(s[j]);
            if (ispalindromic(temp))
            {
                cnt++;
            }
        }
        temp.clear();
    }

    return cnt;
}

int countSubstrings_dp(string s)
{
    int n = s.size();
    int result = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // 从下到上，从左到右
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}

// 中心扩展法

int countSubstrings_centerexpansion(string s)
{
    int cnt = 0;
    int n = s.size();
    // 2*n-1 个中心位置
    // center = 0 2 4 --- 表示奇回文串
    // center = 1 3 5 --- 表示偶回文串
    int L = 0; // 左指针
    int R = 0; // 右指针
    for (int center = 0; center < 2 * n - 1; center++)
    {
        L = center / 2;
        R = L + center % 2;

        while (L >= 0 && R < n && s[L] == s[R] )
        {
            cnt++;
            L--;
            R++;
        }
    }
    return cnt;
}

/*
时间:20250728
516. 最长回文子序列
中等
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/
// 通过率：61 / 86
static void longestPalindromeSubseq_dfs(int index, string s, string &path, int &cnt)
{
    if (path.size())
    {
        if (ispalindromic(path))
        {
            cnt = max(cnt, (int)path.size());
        }
    }
    if (index >= s.size())
    {
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        path.push_back(s[i]);
        longestPalindromeSubseq_dfs(i + 1, s, path, cnt);
        path.pop_back();
    }
}
int longestPalindromeSubseq_bf(string s)
{
    int n = s.size();
    string path;
    int result = 0;
    longestPalindromeSubseq_dfs(0, s, path, result);
    return result;
}

int longestPalindromeSubseq_dp(string s)
{
    int n = s.size();
    // dp[i][j] -- [i j]的字符串的最长回文子序列长度 (i <= j)
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[i][j] = dp[i+1][j-1]
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}
