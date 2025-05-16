/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum +=nums[i];
            result = max(result,sum);
            if(sum<0)
            {
                sum = 0;   
            }
        }
        return result;
    }
};
// @lc code=end
