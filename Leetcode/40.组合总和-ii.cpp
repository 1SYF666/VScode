/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    int sum = 0;
    vector<int> res;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target,int startindex)
    {
        // 终止条件
        if(sum>=target)
        {
            pair <vector<int>,int> key ={res,0};
            if(sum == target)
                result.push_back(res);

            return;
        }
        // 单层逻辑
        for(int i = startindex;i<candidates.size();i++)
        {
            if(i>startindex&&candidates[i]==candidates[i-1]) continue;
            res.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates,target,i+1);
            sum-=candidates[i];
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        backtracking(candidates,target,0);
        return result;
    }
};
// @lc code=end

