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
