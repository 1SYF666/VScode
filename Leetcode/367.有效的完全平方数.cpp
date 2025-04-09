/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int left = 0;
        int right = num-1;
        int mid  = 0;
        if (num == 1)
        {
            return true;
        }
        
        while (left<=right)
        {
            mid = left + (right - left)/2 ;
            long mul = (long)mid*mid;
            if(mul == num)
            {
                return true;
            } 
            else if (mul>num)
            {
                right = mid -1;
            }
            else
            {
                left = mid + 1 ;
            }
        }
        return false;
    }
};
// @lc code=end

