#include <vector>
#include <string>
using namespace std;
/*
时间：20250729 16:05
131. 分割回文串
已解答
中等
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*/

static bool ispalindromic_partition(string s, int st, int end)
{
    while (st <= end)
    {
        if (s[st] == s[end])
        {
            st++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void backtracking_partition(string s, int pos, vector<string> &path, vector<vector<string>> &result)
{
    int n = s.size();
    // 退出
    if (pos >= n)
    {
        result.push_back(path);
        return;
    }

    //
    for (int i = pos; i < n; i++)
    {
        // 判断是否为回文
        if (ispalindromic_partition(s, pos, i))
        {
            // 是
            // 获取[pos i]在s中的子串
            string temp = s.substr(pos, i - pos + 1);
            path.push_back(temp);
        }
        else
        {
            // 不是
            continue;
        }
        // 递归
        backtracking_partition(s, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> path;
    vector<vector<string>> result;
    backtracking_partition(s, 0, path, result);
    return result;
}

/*
时间：20250730 11:29
48. 旋转图像
中等
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

//
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int loop = n / 2; // 共有多少个环

    //(i, j)  <-  (n-1-j, i)  <-  (n-1-i, n-1-j)  <-  (j, n-1-i)

    for (int i = 0; i < loop; i++)
    {
        for (int j = 0; j < n - 2 * i - 1; j++)
        {
            // 开始替换
            int temp = matrix[n - i - 1 - j][i];
            matrix[n - i - 1 - j][i] = matrix[n - i - 1][n - i - 1 - j];
            matrix[n - i - 1][n - i - 1 - j] = matrix[i + j][n - i - 1];
            matrix[i + j][n - i - 1] = matrix[i][i + j];
            matrix[i][i + j] = temp;
        }
    }
}

/*
时间：20250730 15:32
51. N 皇后
已解答
困难
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/
bool isPlace(vector<string> &chessboard, int row, int col)
{
    int jmax = chessboard[0].size();
    if (row == 0)
        return true;
    if (col == 0)
    {
        for (int i = 1; i <= row; i++)
        {
            if (chessboard[row - i][col] == 'Q' || (col + i < jmax && chessboard[row - i][col + i] == 'Q'))
                return false;
        }
    }
    else if (col == chessboard[0].size())
    {
        for (int i = 1; i <= row; i++)
        {
            if (chessboard[row - i][col] == 'Q' || (col - i >= 0 && chessboard[row - i][col - i] == 'Q'))
                return false;
        }
    }
    else
    {
        for (int i = 1; i <= row; i++)
        {
            if (chessboard[row - i][col] == 'Q' || (col + i < jmax && chessboard[row - i][col + i] == 'Q') || (col - i >= 0 && chessboard[row - i][col - i] == 'Q'))
                return false;
        }
    }
    return true;
}
void solveNQueens_dfs(int row, vector<string> &chessboard, vector<vector<string>> &result)
{
    int n = chessboard.size();
    if (row >= n)
    {
        result.push_back(chessboard);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        // 可以放
        if (isPlace(chessboard, row, j))
        {
            chessboard[row][j] = 'Q';
            solveNQueens_dfs(row + 1, chessboard, result);
            chessboard[row][j] = '.';
        }
        else
        {
            // 不可以放
            continue;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> chessboard(n, string(n, '.'));
    solveNQueens_dfs(0, chessboard, result);
    return result;
}
