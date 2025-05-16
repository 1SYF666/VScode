/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int curindex = 0;
        int curindex1 = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            curindex = max(nums[i]+i,curindex);
            if(curindex1==i)
            {
                curindex1 = curindex;
                ans++;
            }

        }
        return ans;
    }
};
// @lc code=end

