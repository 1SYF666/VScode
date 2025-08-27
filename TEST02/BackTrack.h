#include <vector>
#include <string>
using namespace std;
/*
时间: 20250826 14:09
131. 分割回文串
已解答
中等
相关企业
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*/

bool Isparonmics(string s)
{
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
void dfs(string s, int index, vector<string> &path, vector<vector<string>> &ans)
{
    if (index == s.size())
    {
        ans.push_back(path);
        return;
    }
    //
    for (int i = index; i < s.size(); i++)
    {
        string stemp = s.substr(index, i - index + 1);
        if (Isparonmics(stemp))
        {
            path.push_back(stemp);
            dfs(s, i + 1, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> path;
    vector<vector<string>> ans;
    dfs(s, 0, path, ans);
    return ans;
}

/*
时间：20250827 11:02
51. N 皇后
已解答
困难
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/

bool isValid(vector<string> &chessboard, int x, int y,int n)
{

    // 上
    for (int i = x; i >= 0; i--)
    {
        if (chessboard[i][y] == 'Q')
            return false;
    }

    // 左上斜
    for (int i = x, j = y; i >= 0&&j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }

    // 右上斜
    for (int i = x, j = y; i >= 0&&j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }
    return true;
}

void Nqueendfs(vector<string> &chessboard, int row,int n ,vector<vector<string>> &ans)
{
    if (row == chessboard.size())
    {
        ans.push_back(chessboard);
        return;
    }
    for (int col = 0; col < chessboard[0].size(); col++)
    {
        if (isValid(chessboard, row, col,n))
        {
            chessboard[row][col] = 'Q';
            Nqueendfs(chessboard, row + 1,n, ans);
            chessboard[row][col] = '.';
        }
    }
}
//#include <iostream>
vector<vector<string>> Nqueen(int n)
{
    vector<vector<string>> ans;
    vector<string> chessboard(n, string(n, '.'));
    Nqueendfs(chessboard, 0,n, ans);
    return ans;
}
