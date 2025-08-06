#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
时间:20250806 16:18
18. 四数之和
已解答
中等
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); //  从小到大排序
    int n = nums.size();
    for (int i = 0; i < n;)
    {
        if (nums[i] > target && nums[i] >= 0)
        {
            break; // 这里使用break，统一通过最后的return返回
        }
        long target3 = target - nums[i];

        // 不重复的三数之和
        for (int j = i + 1; j < n;)
        {
            if (nums[j] > target3 && nums[j] >= 0)
            {
                break;  // pay attention
            }

            int left = j + 1;
            int right = n - 1;
            long target2 = target3 - nums[j];

            while (left < right)
            {
                long sum = nums[left] + nums[right];
                if (sum > target2)
                {
                    right--;
                }
                else if (sum < target2)
                {
                    left++;
                }
                else
                {
                    int third = nums[left];
                    int fourth = nums[right];
                    result.push_back({nums[i], nums[j], third, fourth});
                    // 去重
                    while (left < right && nums[left] == third)
                    {
                        left++;
                    }
                    while (left < right && nums[right] == fourth)
                    {
                        right--;
                    }
                }
            }
            // 第二个数去重
            int second = nums[j];
            while (j < n && nums[j] == second)
            {
                j++;
            }
        }
        // 第一个数 去重
        int first = nums[i];
        while (i < n && nums[i] == first)
        {
            i++;
        }
    }
    return result;
}

/*
时间:20250806
15. 三数之和
已解答
中等
提示
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/

vector<vector<int>> threeSum(vector<int> &nums) // target = 0
{
    vector<vector<int>> result;
    int target = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n;)
    {
        if (nums[i] > target)
            break;
        int sumtarget = target - nums[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            if (left < right && sumtarget > nums[left] + nums[right])
            {
                left++;
            }
            else if (left < right &&
                     sumtarget < nums[left] + nums[right])
            {
                right--;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // 去重 第二个数
                int second = nums[left];
                while (left < right && nums[left] == second)
                {
                    left++;
                }
                // 去重 第三个数
                int third = nums[right];
                while (left < right && nums[right] == third)
                {
                    right--;
                }
            }
        }

        // 去重第一个数
        int first = nums[i];
        while (i < n && nums[i] == first)
        {
            i++;
        }
    }
    return result;
}

/*
时间:20250806 14:26
11. 盛最多水的容器
中等
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
*/

int maxArea(vector<int> &height)
{
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int sum = 0;
    while (left < right)
    {
        sum = max(sum, min(height[left], height[right]) * (right - left));

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return sum;
}
int maxAreav2(vector<int> &height)
{
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int sum = 0;
    int temp = 0;
    while (left < right)
    {
        sum = max(sum, min(height[left], height[right]) * (right - left));

        if (height[left] < height[right])
        {
            temp = height[left];
            while (left < right && height[left] <= temp)
            {
                left++;
            }
        }
        else
        {
            temp = height[right];
            while (left < right && height[right] <= temp)
            {
                right--;
            }
        }
    }
    return sum;
}

// 超时：58 / 65
int maxArea_bf(vector<int> &height)
{
    int n = height.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = max(min(height[i], height[j]) * (j - i), sum);
        }
        result = max(result, sum);
    }
    return result;
}

/*
时间:20250806 14:08
283. 移动零
已解答
简单
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

void swapself(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    while (right < n)
    {
        if (nums[right])
        {
            swapself(&nums[left], &nums[right]);
            left++;
        }
        right++;
    }
    return;
}

void moveZeroes_low(vector<int> &nums)
{
    int first = 0;
    int second = 0;
    int n = nums.size();
    while (first < n && second < n)
    {
        //
        if (nums[first] != 0)
        {
            first++;
            second = first;
        }
        else
        {
            while (second < n && nums[second] == 0)
                second++;
            if (second == n)
                return;
            swapself(&nums[first], &nums[second]);
            first++;
            second = first;
        }
    }
    return;
}
