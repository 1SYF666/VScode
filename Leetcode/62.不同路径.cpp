// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem62.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> maxtrix(m,vector<int>(n,0));
        vector<vector<int>> maxtrix(m,vector<int>(n,1));
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                maxtrix[i][j] = maxtrix[i][j-1] + maxtrix[i-1][j];
            }
        }
        return maxtrix[m-1][n-1];
        
    }
};
// @lc code=end
