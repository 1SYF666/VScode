/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int pre = 1;   // 当前字符的前一字符所拥有的解码方法总数，即nums[i-1]
        int prepre = 0; // 当前字符的前一字符所拥有的解码方法总数，即nums[i-2]
        
        for (int i = 0; i < s.length(); ++i)
        {
            int cur = 0;
            if(s[i]!='0')
            {
                cur = pre;  // 情况1
            }
            if (i>0&&s[i-1]!='0')
            {
                if((s[i-1]-'0')*10+s[i]-'0'<=26)
                {
                    cur+=prepre; // 情况2
                }
            }
            
            // 更新
            prepre = pre;
            pre = cur;
        }
        
        return pre;
    }
};
// @lc code=end

