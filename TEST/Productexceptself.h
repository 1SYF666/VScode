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