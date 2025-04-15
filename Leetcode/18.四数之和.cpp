// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long sum = 0;
        int left = 0;
        int right = 0;
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        target = (long long)target;
        if(nums.size()<4)
        {
            return result;
        }
        long long sum1 = (long long)nums[0]+nums[1]+nums[2]+nums[3];
        long long sum2 = (long long)nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3]+nums[nums.size()-4];
        if(sum1>target||sum2<target)
        {
            return result;
        }

        for (i = 0; i < nums.size(); i++)
        {
            // a 去重
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            for (j = i+1 ; j < nums.size(); j++)
            {
                // b去重
                if(j>i+1&&nums[j]==nums[j-1])
                {
                    continue;
                }
                
                left = j+1;
                right = nums.size()-1;

                while (left<right)
                {
                    sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                    if(sum<target)
                    {
                        left++;
                    }
                    else if(sum>target)
                    {
                        right --;
                    }
                    else
                    {
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // c去重
                        while (left<right && nums[left]==nums[left+1])
                        {
                            left++;
                        }
                        // d去重
                        while (left<right && nums[right]==nums[right-1])
                        {
                            right--;
                        }
                        // 移动
                        left ++;
                        right--;
                    }

                }
            }
            
        }
        
        return result;
    }
};
// @lc code=end

