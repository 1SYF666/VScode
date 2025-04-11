// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem904.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int start = 0;
        int n = fruits.size();
        int max = 0;
        unordered_map<int,int>ftemp;

        for (i = 0; i < n; i++)
        {
            ++ftemp[fruits[i]];

            while (ftemp.size() > 2)
            {
                if (--ftemp[fruits[start]]==0)
                {
                    ftemp.erase(fruits[start]);
                    
                }
                start++;
            }
            max = max > i-start+1?max:i-start+1;
        }

        return max;
    }
};
// @lc code=end

