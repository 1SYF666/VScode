// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem47.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<int> res;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums,vector<bool>& used)
    {
        if(res.size()==nums.size())
        {
            result.push_back(res);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]&&used[i-1] == false)
            continue;
            if(used[i]== false)
            {
                used[i] = true;
                res.push_back(nums[i]);
                backtracking(nums,used);
                res.pop_back();
                used[i] = false;
            }
        }

    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool>used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
// @lc code=end

