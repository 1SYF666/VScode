/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int index = s.size()-1;

        for(int i = g.size()-1 ; i>=0 ; i--)
        {
            if(index>=0&&s[index]>=g[i])
            {
                count++;
                index--;
            }
        }

        return count;
        
    }
};
// @lc code=end

