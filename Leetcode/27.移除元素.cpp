/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        int fast = 0;
        for ( fast = 0; fast < nums.size(); fast++)
        {
            if (val != nums[fast])
            {
                nums[slow++]=nums[fast];
            }
            
        }
        return slow;
    }
};
// @lc code=end
