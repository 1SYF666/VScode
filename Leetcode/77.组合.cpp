// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(n, k, 1, cur, res);
        return res;
    }
    void dfs(int n, int k, int level, vector<int> &cur, vector<vector<int>> &res)
    {
        if (cur.size() == k)
        {
            res.push_back(cur);
            return;
        }
        for (int i = level; i <= n; ++i)
        {
            cur.push_back(i);
            dfs(n, k, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
// @lc code=end
