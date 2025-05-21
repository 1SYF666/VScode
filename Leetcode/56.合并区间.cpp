/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[0]<b[0];  // 升序排列
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        if(intervals.size()<2) return intervals;
        
        sort(intervals.begin(),intervals.end(),cmp);
        result.push_back(intervals[0]);

        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=result.back()[1])
            {
                result.back()[1] = max(intervals[i][1],result.back()[1]);
            }
           else
           {
                result.push_back(intervals[i]);
           } 

        }
        return result;        
    }
};
// @lc code=end

