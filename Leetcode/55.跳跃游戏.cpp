// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > reach || reach >= n - 1)
                break;
            reach = max(reach,i+nums[i]);
        }
        return reach >=n-1;
    }
};
// @lc code=end
