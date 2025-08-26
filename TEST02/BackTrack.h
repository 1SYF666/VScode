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
void dfs(string s, int index,vector<string>& path,vector<vector<string>>& ans)
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
            dfs(s, i + 1,path,ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> path;
    vector<vector<string>> ans;
    dfs(s, 0,path,ans);
    return ans;
}
