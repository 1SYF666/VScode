/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> result_set;
        int sumsqure = n;
        while (1)
        {
            sumsqure = getsumsqure(sumsqure);
            if (sumsqure == 1)
            {
                return true;
            }

            if (result_set.find(sumsqure) != result_set.end())
            {
                return false;
            }else
            {
                result_set.insert(sumsqure);
            }
        }
    }
    int getsumsqure(int n)
    {
        int result = 0;
        int remain = 0;
        int divd = 0;
        int temp = n;

        while (temp > 0)
        {

            divd = temp / 10;
            remain = temp % 10;
            result += remain * remain;
            temp = divd;
        }
        return result;
    }
};
// @lc code=end
