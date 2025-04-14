// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for (string strr : strs)
        {
            string temp = strr;
            sort(strr.begin(),strr.end());
            groups[strr].push_back(temp);
        }
        
        // 收集结果
        vector<vector<string>> result;
        // for(auto& pair : groups)
        // {
        //     result.push_back(pair.second);
        // }

        for(auto it=groups.begin();it != groups.end();it++)
        {
            result.push_back(it->second);
        }


        return result;

    }
};
// @lc code=end

