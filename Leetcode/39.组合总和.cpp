/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    int sum  = 0;
    vector<int>res;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates,int target,int index)
    {
        // 终止条件
        if(sum >= target)
        {
            if(sum == target) result.push_back(res);
            return ;
        }
        // 单层逻辑
        for(int i = index;i<candidates.size();i++)
        {
            res.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates,target,i);
            sum-=candidates[i];
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};
// @lc code=end

