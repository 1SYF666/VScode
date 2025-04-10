// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        int result = 0;
        int sublen = 0;
        int flag = 0;
        int i =0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while ( sum >= target)
            {
                sublen = j - i + 1;
                if (!flag)
                {
                   result = sublen;
                   flag = 1;
                }
                result = result<sublen?result:sublen;
                sum -=nums[i++];
            }
        }
        return result;        
    }
};
// @lc code=end

