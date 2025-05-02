/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:

    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void backtracking(int k, int n,int startindex)
    {
        // 终止条件
        if(path.size()==k)
        {
            if(sum == n)
            {
                result.push_back(path);
            }
            return;
        }

        // 单层逻辑
        for(int i = startindex;i<=9;i++)
        {
            path.push_back(i);
            sum +=i;
            backtracking(k,n,i+1);
            sum -=i;
            path.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return result;
    }
};
// @lc code=end

