/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<int>res;
    vector<vector<int>> result;
    void backtracking(vector<int>&nums,vector<bool>& used)
    {
        if(res.size() == nums.size())
        {
            result.push_back(res);
            return ;
        }
        // 单层逻辑
        for(int i = 0;i<nums.size();i++)
        {
            if(used[i]==true)
                continue;
            used[i] = true;
            res.push_back(nums[i]);
            backtracking(nums,used);
            res.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
// @lc code=end

