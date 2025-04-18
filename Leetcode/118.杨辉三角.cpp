/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());

        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i+1,1);
            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
// @lc code=end

