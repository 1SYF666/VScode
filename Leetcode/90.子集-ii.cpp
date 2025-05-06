// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
private:
vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int> &nums,int startindex,vector<bool>& used)
{
    result.push_back(path);   // 收集子集
    // 终止条件
    if (startindex>=nums.size())
    {
        return ;
    }

    // 单层循环
    for (int i = startindex; i < nums.size(); i++)
    {
        if (i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
        {
            continue;
        }
        
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums,i+1,used);
        used[i] = false;
        path.pop_back();
    }
}


public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());    // 去重需要排序
        backtracking(nums,0,used);
        return result;
    }
};
// @lc code=end
