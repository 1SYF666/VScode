#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
/*
时间: 20250707 11:15
215. 数组中的第K个最大元素
中等
    给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
    请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

// 暴力求解
bool static comp(int a, int b)
{
    return a > b;
}
int findKthlargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end(), comp);
    return nums[k - 1];
}

// O(n)解法 -- 代码依旧超时
int static partition(vector<int> &nums, int startindex, int endindex)
{

    int pivot = nums[startindex];
    int pivotindex = startindex;
    int left = startindex;
    int right = endindex;
    // 左边放小于pivot ,右边放大于pivot
    while (left < right)
    {

        while (left < right)
        {
            if (nums[right] < pivot)
            {
                nums[left] = nums[right];
                pivotindex = right;
                left++;
                break;
            }
            right--;
        }

        while (left < right)
        {
            if (nums[left] > pivot)
            {
                nums[right] = nums[left];
                pivotindex = left;
                right--;
                break;
            }
            left++;
        }
    }
    nums[pivotindex] = pivot;
    return pivotindex;
}
void static quicksort(vector<int> &nums, int left, int right)
{
    if (right - left <= 0)
        return;
    int par = partition(nums, left, right);
    quicksort(nums, left, par - 1);
    quicksort(nums, par + 1, right);
}

int findKthlargest_On(vector<int> &nums, int k)
{
    quicksort(nums, 0, nums.size() - 1);
    for (int i = nums.size() - 1; i >= nums.size() - k; i--)
    {
        if (i == nums.size() - k)
            return nums[i];
    }
    return 0;
}

// 新版本
int findKthlargest_On_v2(vector<int> &nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;
    while (true)
    {
        // 左小 中枢 右大
        int pos = partition(nums, left, right);
        if (pos == nums.size() - k)
            return nums[pos];
        if (pos > nums.size() - k)
            right = pos - 1;
        if (pos < nums.size() - k)
            left = pos + 1;
    }
}

/*
时间: 20250707 11:15
198. 打家劫舍
中等
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

// 动态规划--- 这道题我没看任何题解，自己独立想出的动态规划解题方法。嘻嘻
int rob(vector<int> nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
    // 初始化
    dp[0][1] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
}
int rob_v2(vector<int> nums)
{
    vector<int> dp(nums.size(),0);
    // 初始化
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(i>=2)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        else
        {
            dp[i] = max(dp[i-1],nums[i]);
        }
    }
    return dp[nums.size()-1];
}


/*
时间: 20250713 16:49
139. 单词拆分
中等
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/

// 查找字符串对应的索引
int cmpstr_bf(string str, string substr)
{
    int i = 0, j = 0;
    int Lenlong = str.size();
    int lenshort = substr.size();

    while (i < Lenlong)
    {
        if (str[i] - 'a' == substr[j] - 'a')
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j = 0;
            if (i == Lenlong - lenshort + 1)
            {
                break;
            }
        }
        if (j == lenshort)
            return i - lenshort;
    }
    return -1; // 没找到
}

// 排序
static bool cmp(string a, string b)
{
    return a.size() < b.size();
}

// 暴力求解 解答错误：s = "cars",worddict = {"car","ca","rs"} return true;
bool wordbreak_bf(string s, vector<string> &wordDict)
{
    string stemp;
    string str = s;
    int st = 0;

    for (int i = 0; i < wordDict.size();)
    {
        stemp = wordDict[i];
        st = cmpstr_bf(str, stemp);
        if (st == -1)
        {
            i++;
            continue;
        }
        else
        {
            string strtemp = str;
            str.clear();
            // 剔除已找到的单词
            for (int j = 0; j < st; j++)
            {
                str.push_back(strtemp[j]);
            }
            for (int j = st + stemp.size(); j < strtemp.size(); j++)
            {
                str.push_back(strtemp[j]);
            }
            if (str.size() == 0)
            {
                return true;
            }
            i = 0;
        }
    }

    return false;
}

bool wordbreak(string s, vector<string> &wordDict)
{
    bool a = wordbreak_bf(s, wordDict);
    sort(wordDict.begin(), wordDict.end(), cmp);
    bool b = wordbreak_bf(s, wordDict);
    return a || b;
}

// 暴力求解正确版--上面是解题思路错误 （应该那切分s中子串 与字典中字符串比较）
static bool wordbreak_bt(string s, int pos, unordered_set<string> m)
{
    int n = s.size();
    if (pos == n)
        return true;

    for (int i = pos + 1; i <= n; i++)
    {
        // 取 s[pos..i-1] 作为一个候选单词
        string w = s.substr(pos, i-pos);
        if (m.count(w))
        {
            if (wordbreak_bt(s, i, m))
                return true;
        }
    }
    return false;
}

bool wordbreak_brutal(string s, vector<string> &wordDict)
{
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    return wordbreak_bt(s, 0, m);
}

// 动态规划求解
