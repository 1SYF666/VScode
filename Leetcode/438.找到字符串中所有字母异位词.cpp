// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    
        if (s.length()<p.length())
        {
            return {}; 
        }
        
        vector<int>pfreq(26,0);
        vector<int>slipwindow(26,0);
        vector<int> result;
        for (int i = 0;i<p.length();i++)
        {
            pfreq[p[i]-'a']++;
        }
        int lenwindow = p.length();
        
        for (int i = 0; i <lenwindow ; i++)
        {
            slipwindow[s[i]-'a']++;
        }
        if (slipwindow==pfreq)
        {
            result.push_back(0);
        }

        for (int i = lenwindow; i < s.length(); i++)
        {
            slipwindow[s[i-lenwindow]-'a']--;
            slipwindow[s[i]-'a']++;
            if (slipwindow==pfreq)
            {
                result.push_back(i-lenwindow+1);
            }
        }

        return result;     

    }
};
// @lc code=end

