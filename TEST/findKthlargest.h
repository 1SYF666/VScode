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
        if(i == nums.size()-k )
            return nums[i];
    }
    return 0;
}
