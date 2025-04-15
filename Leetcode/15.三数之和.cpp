/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 0;
        int sum = 0 ;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            left = i + 1;
            right = nums.size()-1;
            // a去重
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }

            while (left<right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                {
                    right--;
                }
                else if (sum<0)
                {
                    left++;
                }
                else
                {
                    result.push_back({nums[i],nums[left],nums[right]});

                    // b 去重
                    while(left<right&&nums[left]==nums[left+1])
                    {
                        left ++;
                    }
                    // c 去重
                    while(left<right&&nums[right]==nums[right-1])
                    {
                        right --;
                    }
                    left ++;
                    right --;

                }
            }
        }
        return result;
    }
};
// @lc code=end
