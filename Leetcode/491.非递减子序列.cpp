/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
private:
    vector<int> res;
    vector<vector<int>> result;
    void backttacking(vector<int>& nums,int startindex)
    {
        //
        if(res.size()>1)
        {
            result.push_back(res);
        }
        if(startindex>=nums.size())
        return;
        
        // 单层逻辑
        unordered_set<int> sets;
        for (int i = startindex; i < nums.size(); i++)
        {
            if(res.size()>=1&&nums[i]<res.back()||sets.find(nums[i])!=sets.end())
                continue;
            sets.insert(nums[i]);
            res.push_back(nums[i]);
            backttacking(nums,i+1);
            res.pop_back();
        }
        
    }


public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backttacking(nums,0);
        return result;
        
    }
};
// @lc code=end

