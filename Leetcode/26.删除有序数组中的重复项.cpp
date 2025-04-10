/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 1;
        }
        int slow = 1;
        int fast = 1;
        
        for (fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow-1])
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;

    }
};
// @lc code=end

