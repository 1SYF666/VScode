/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> temp;

        //初始化
        for (char u:magazine)
        {
            temp[u]++;
        }

        for (char i:ransomNote)
        {
            temp[i]--;
            if (temp[i]<0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

