/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int hash[27] = {0};
        for(int i = 0;i<s.size();i++)
        {
            hash[s[i]-'a'] = i;
        }

        int left = 0;
        int right = 0;
        for(int i = 0;i<s.size();i++)
        {
            right = max(right,hash[s[i]-'a']);
            if(right == i)
            {
                result.push_back(right-left+1);
                left = right + 1;
            }
        }
        return result;        
    }
};
// @lc code=end

