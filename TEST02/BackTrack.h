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

bool isValid(vector<string> &chessboard, int x, int y, int n)
{

    // 上
    for (int i = x; i >= 0; i--)
    {
        if (chessboard[i][y] == 'Q')
            return false;
    }

    // 左上斜
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }

    // 右上斜
    for (int i = x, j = y; i >= 0 && j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')
            return false;
    }
    return true;
}

void Nqueendfs(vector<string> &chessboard, int row, int n, vector<vector<string>> &ans)
{
    if (row == chessboard.size())
    {
        ans.push_back(chessboard);
        return;
    }
    for (int col = 0; col < chessboard[0].size(); col++)
    {
        if (isValid(chessboard, row, col, n))
        {
            chessboard[row][col] = 'Q';
            Nqueendfs(chessboard, row + 1, n, ans);
            chessboard[row][col] = '.';
        }
    }
}
#include <iostream>
vector<vector<string>> Nqueen(int n)
{
    vector<vector<string>> ans;
    vector<string> chessboard(n, string(n, '.'));
    Nqueendfs(chessboard, 0, n, ans);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << "\"";
            for (int k = 0; k < ans[i][j].size(); k++)
            {
                cout << ans[i][j][k];
            }
            cout << "\"" << ((j + 1 < ans[i].size()) ? "," : "");
        }
        cout << "]" << ((i + 1 < ans.size()) ? "," : "");
    }
    cout << "]" << endl;
    return ans;
}

/*
时间：20250827 15:32
93. 复原 IP 地址
已解答
中等
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/
// 已通过-- 但是代码冗余
void IPaddressDFS(string s, int index, int count, string &path, vector<string> &ans)
{
    //
    if (count > 4)
        return;
    if (index == s.size() && count == 4)
    {

        ans.push_back(path.substr(0, path.size() - 1));
        return;
    }

    //
    for (int i = index; i < s.size(); i++)
    {
        string stemp = s.substr(index, i - index + 1);
        long long nums = stoll(stemp);
        if ((nums > 0 && nums <= 255 && stemp[0] != '0') || (nums == 0 && stemp.size() == 1))
        {
            path += stemp;
            path += ".";
            IPaddressDFS(s, i + 1, count + 1, path, ans);
            for (int k = 0; k <= stemp.size(); k++)
                path.pop_back();
        }
    }
}

vector<string> IPaddress(string s)
{
    string path;
    vector<string> ans;
    if (s.size() > 3 && s.size() <= 12)
        IPaddressDFS(s, 0, 0, path, ans);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\"";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << "\"" << (i + 1 < ans.size() ? "," : "");
    }
    cout << "]" << endl;
    return ans;
}

/*
时间:20250827 19:31
240. 搜索二维矩阵 II
已解答
中等
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/
bool searchnum(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int m = 0;
    int n = col - 1;
    while (m < row && n >= 0)
    {
        if (matrix[m][n] == target)
            return true;
        else if (matrix[m][n] < target)
            m++;
        else
            n--;
    }
    return false;
}
