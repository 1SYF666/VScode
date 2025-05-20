/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
                int a = 0;
        int b = 0;
        for(int i = 0;i<bills.size();i++)
        {
            if(bills[i]==5)a++;
            else if(bills[i]==10)
            {
                b++;
                if(a>0)
                    a--;
                else
                    return false;
            }
            else 
            {
                if(a>0&&b>0)
                {
                    a--;
                    b--;
                }
                else if(a>=3)
                {
                    a-=3;
                }
                else 
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

