/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        char temp;
        while (left<right)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left ++;
            right --;
        }
    }
};
// @lc code=end

