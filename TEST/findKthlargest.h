#include <vector>
#include <deque>
#include <algorithm>
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
