/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> queue(n, string(n, '.'));
        dfs(0, res, queue);
        return res;
    }

    void dfs(int row, vector<vector<string>> &res, vector<string> &queue)
    {
        int n = queue.size();
        if (row == n)
        {
            res.push_back(queue);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isValid(row, j, queue))
            {
                queue[row][j] = 'Q';
                dfs(row + 1, res, queue);
                queue[row][j] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &queue)
    {
        // 竖线
        for (int i = 0; i < row; i++)
        {
            if (queue[i][col] =='Q')
                return false;
        }

        // 斜线
        for (int i = row-1,j = col-1;i>=0&&j>=0; i--,j--)
        {
            if (queue[i][j] =='Q')
                return false;
        }

        // 对角斜线
        for (int i = row-1 ,j = col+1; i>=0&&j<queue.size();i--,j++)
        {
            if (queue[i][j] =='Q')
                return false;
        }
        return true;
    }
};
// @lc code=end
