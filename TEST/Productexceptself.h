#include <vector>
using namespace std;
/*
时间:20250721 16:45
238. 除自身以外数组的乘积
中等
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/
// 通过率:18/24
vector<int> productExceptSelf_bf(vector<int> &nums)
{
    int len = nums.size();
    int multiple = 1;
    vector<int> result(len, 0);
    for (int i = 0; i < len; i++)
    {
        multiple = 1;
        for (int j = 0; j < len; j++)
        {
            if (j == i)
            {
                continue;
            }
            multiple *= nums[j];
        }
        result[i] = multiple;
    }
    return result;
}

//
vector<int> productExceptSelf(vector<int> &nums)
{
    int len = nums.size();
    // 前缀积
    vector<int> prefixproduct(nums.size(), 1);
    for (int i = 1; i < len; i++)
    {
        prefixproduct[i] = prefixproduct[i - 1] * nums[i - 1];
    }

    // 后缀积
    vector<int> suffixproduct(nums.size(), 1);
    for (int i = len - 2; i >= 0; i--)
    {
        suffixproduct[i] = suffixproduct[i + 1] * nums[i + 1];
    }

    // 输出
    for (int i = 0; i < len; i++)
    {
        prefixproduct[i] *= suffixproduct[i];
    }
    return prefixproduct;
}

vector<int> productExceptSelfv2(vector<int> &nums)
{
    int len = nums.size();
    // 前缀积
    vector<int> prefixproduct(nums.size(), 1);
    for (int i = 1; i < len; i++)
    {
        prefixproduct[i] = prefixproduct[i - 1] * nums[i - 1];
    }

    // 后缀积 和 输出
    int temp = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        // suffixproduct[i] = suffixproduct[i + 1] * nums[i + 1];
        prefixproduct[i] *= temp;
        temp *= nums[i];
    }

    return prefixproduct;
}

/*
时间:20250722 14:54
300. 最长递增子序列
中等
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/
// 通过率：36/55
static void lengthOfLTSbacktracking(int index, const vector<int> &nums, vector<int> &path, int &best)
{
    int n = nums.size();
    // 退出
    // 剪枝
    if ((int)path.size() + (n - index) <= best)
        return;

    if (index == n)
    {
        best = max(best, (int)path.size());
        return;
    }

    // 开始遍历
    for (int i = index; i < n; i++)
    {
        if (path.empty()||nums[i]>path.back())
        {
            path.push_back(nums[i]);
            lengthOfLTSbacktracking(i + 1, nums, path, best);
            path.pop_back();
        }
    }
    best = max(best, (int)path.size());
}

int lengthOfLTS_bf(vector<int> &nums)
{
    int result = 0;
    vector<int> path;
    lengthOfLTSbacktracking(0, nums, path, result);
    return result;
}
