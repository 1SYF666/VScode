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

// O(n)解法
int findKthlargest_On(vector<int> &nums, int k)
{
    
}
