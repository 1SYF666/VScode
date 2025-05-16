/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
    private:
    static bool cmp(int a,int b)
    {
        return abs(a)>abs(b);  // 绝对值从大到小排
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp); 
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]<0&&k>0)
            {
                nums[i]*=-1;
                k--;
            }
        }
        if(k%2==1)
        {
            nums[nums.size()-1]*=-1;
        }
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        return sum;
        
    }
};
// @lc code=end

