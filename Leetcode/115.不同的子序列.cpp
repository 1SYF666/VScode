/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) return 0;
        if(t.size()== s.size()) return s==t;
        vector < long> dp(t.size()+1,0);  
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i){
          for(int j =static_cast(t.size())-1; j>=0; --j){
            //dp[j] means number of subsequence that has matched j char in t, need to compare with t[j]
            if(t[j]==s[i]){
              dp[j+1] += dp[j];//use this character, so dp[j+1] should be modified
              //at the same time keep dp[j] unchanged, which means skip this character
            }
          }  
        }
        return dp.back();
        
    }
};
// @lc code=end

