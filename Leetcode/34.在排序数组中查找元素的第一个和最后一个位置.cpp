// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right =  getrightrangr(nums,target);
        int left =  getleftrangr(nums,target);

        if (right == -2 || left == -2)
        {
            return {-1,-1};
        }
        if (right-left>1)
        {
            return {left+1,right-1};
        }
        return {-1,-1};
    }

    int getrightrangr(vector<int>&nums,int target)
    {
        int left = 0;
        int right = nums.size()-1;
        int getrightborder = -2;
        int mid = 0;

        while (left<=right)
        {
            mid = left + (right - left)/2;
            if (nums[mid]<=target)
            {
                left = mid + 1;
                getrightborder = left;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return getrightborder;
    }

    int getleftrangr(vector<int>&nums,int target)
    {
        int left = 0;
        int right = nums.size()-1;
        int getleftborder = -2;
        int mid = 0;

        while (left<=right)
        {
           mid = left + (right - left)/2;
           if (nums[mid]<target)
            {
                left  = mid +1;
            }
           else
           {
                right = mid-1;
                getleftborder = right;

           }
           
        }

        return getleftborder;
    }

};
// @lc code=end

