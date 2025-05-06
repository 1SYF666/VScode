// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
private:
vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int> &nums,int startindex)
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
        path.push_back(nums[i]);
        backtracking(nums,i+1);
        path.pop_back();
    }
}

public:


    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        path.clear();
        backtracking(nums,0);
        return result;
    }

};
// @lc code=end
