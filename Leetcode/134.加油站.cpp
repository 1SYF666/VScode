/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0;
        int totalremain = 0;
        int start = 0;
        for(int i = 0;i<gas.size();i++)
        {
            remain += (gas[i]-cost[i]);
            totalremain+=(gas[i]-cost[i]);
            if(remain<0)
            {
                start = i+1;
                remain = 0;
            }
        }
        if(totalremain<0) return -1;
        return start;
    }
};
// @lc code=end

