// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem343.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n<=0) return 0;
        vector<int> dp(n+1,1);
        for(int i = 3;i<=n;i++)
        {
            for(int j = 1;j<i;j++)
                dp[i] = max(max(dp[i-j]*j,(i-j)*j),dp[i]);
        }
        return dp[n];
    }
};
// @lc code=end

