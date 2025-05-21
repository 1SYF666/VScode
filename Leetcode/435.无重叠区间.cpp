/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return 0;
        
        sort(intervals.begin(),intervals.end(),cmp); // 排序

        int result = 0;
        for(int i =1;i<intervals.size();i++)
        {
            if(intervals[i][0]<intervals[i-1][1])
            {
                result++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
                // intervals.erase(intervals.begin()+i);
                // i--;
            }
        }
        return result;        
    }
};
// @lc code=end

