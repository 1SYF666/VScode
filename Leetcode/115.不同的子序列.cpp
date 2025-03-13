/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1000000007;
        int m = s.length(),n = t.length();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        
        // 初始化：t为空时，方案数为1
        for (int j = 0; j <= m; j++)
        {
            /* code */
            dp[j][0] = 1;
        }
        // 填充dp的数组
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
                }
                else
                {
                    dp[i][j] = dp[i-1][j]%MOD;
                }
            }
            
        }
        return dp[m][n];
        
    }
};
// @lc code=end

