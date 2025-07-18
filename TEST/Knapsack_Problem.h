#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

/*
时间: 20250630 14:20
01 背包
    有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
    每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
example 1：
    背包最大重量为4。
    物品    重量	价值
    物品0	1       15
    物品1	3       20
    物品2	4       30
    背包能带的物品最大价值是多少？
*/

// 回溯法（暴力解决）

void backtracking(int index, int currentWeight, int currentValue, int maxweight,
                  const vector<int> &weight, const vector<int> &value, int &maxValue)
{
    // 退出
    if (index >= weight.size() || currentWeight > maxweight)
    {
        maxValue = max(maxValue, currentValue);
        return;
    }

    // 不选择当前数据
    backtracking(index + 1, currentWeight, currentValue, maxweight, weight, value, maxValue);
    // 选择当前数据
    if (currentWeight + weight[index] <= maxweight)
    {
        backtracking(index + 1, currentWeight + weight[index], currentValue + value[index],
                     maxweight, weight, value, maxValue);
    }
}

// 动态规划
int DynamicProgramming_exp1()
{
    // 物品:下标索引0 1 2
    int maxweight = 4;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    // dp数组
    vector<vector<int>> dp(weight.size(), vector<int>(maxweight + 1, 0));

    // 初始化第一行
    for (int j = weight[0]; j <= maxweight; j++)
    {
        dp[0][j] = value[0];
    }

    // 开始遍历
    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = 0; j <= maxweight; j++)
        {
            if (j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    return dp[weight.size() - 1][maxweight];
}

/*
时间: 20250701 14:54
416. 分割等和子集 ---- 力扣题目链接(opens new window)
题目难易：中等
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
*/

// 回溯法（暴力解决）

bool backtracking2(int index, int currentsum, int maxvalue, const vector<int> &nums, vector<int> &result)
{
    // 终止条件
    if (currentsum == maxvalue)
    {
        return true;
    }

    if (index >= nums.size() || currentsum > maxvalue)
    {
        return false;
    }

    // 选择
    if (currentsum + nums[index] <= maxvalue)
    {
        result.push_back(nums[index]);
        if (backtracking2(index + 1, currentsum + nums[index], maxvalue, nums, result))
            return true;

        // 回溯
        result.pop_back();
    }

    // 不选择
    return backtracking2(index + 1, currentsum, maxvalue, nums, result);
}

bool example2(vector<int> &result1, vector<int> &result2)
{
    int sum = 0;
    // 物品:下标索引0 1 2 3
    vector<int> nums = {1, 5, 11, 5};
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // 奇数直接false
    if (sum % 2)
        return false;
    int mid = sum / 2;

    bool flag = backtracking2(0, 0, mid, nums, result1);

    if (flag)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int flag1 = 1;
            for (int j = 0; j < result1.size(); j++)
            {
                if (nums[i] == result1[j])
                    flag1 = 0;
            }
            if (flag1)
                result2.push_back(nums[i]);
        }
    }

    return flag;
}
/*
    时间: 20250701 14:54
*/
// 动态规划
bool DynamicProgramming_exp2()
{
    int sum = 0;
    // 物品:下标索引0 1 2 3
    vector<int> nums = {1, 2, 3, 5};
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // 奇数直接false
    if (sum % 2)
        return false;
    int mid = sum / 2;

    vector<int> dp(mid + 1, 0);
    // 开始 01背包
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = mid; j >= nums[i]; j--)
        { // 每一个元素一定是不可重复放入，所以从大到小遍历
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if (dp[mid] == mid)
        return true;
    else
        return false;
}

/*
时间: 20250703 19:06
难度：中等
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/

// 回溯法（暴力解决）

void backtracking3(int index, int currentsum, int &count, vector<int> &nums, int target)
{
    // 终止条件
    if (index == nums.size())
    {
        if (currentsum == target)
        {
            count++;
        }
        return;
    }

    // 选择加法
    backtracking3(index + 1, currentsum + nums[index], count, nums, target);
    // 选择减法
    backtracking3(index + 1, currentsum - nums[index], count, nums, target);
}

// 动态规划
int DynamicProgramming_exp3(vector<int> &nums, int target)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if(abs(target)>sum) return 0;  // 此时没有方案
    if((target+sum)%2==1) return 0; // 此时没有方案

    int bagsize = (target + sum) / 2;

    vector<vector<int>> dp(nums.size(), vector<int>(bagsize + 1, 0));

    // 初始化 ---- 行
    if (nums[0] <= bagsize)
        dp[0][nums[0]] = 1;

    // 初始化 ---- 列
    dp[0][0] = 1;

    int numZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            numZero++;
        dp[i][0] = (int)pow(2.0, numZero);
    }

    // 遍历
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j <= bagsize; j++)
        {
            if (nums[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
        }
    }

    return dp[nums.size()-1][bagsize];
}

/*
时间: 20250704 15:37
474.一和零
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/

// 暴力解法
void backtracking4(vector<string>& str,int index,vector<string>& path,vector<vector<string>>& subsets)
{
    subsets.push_back(path);
    if(index>=str.size())
    {
        return;
    }

    for(int i = index;i<str.size();i++)
    {
        path.push_back(str[i]);
        backtracking4(str,i+1,path,subsets);
        path.pop_back();
    }
}

void example4(vector<string>& strs,int m,int n,int& result)
{
    
    vector<string> path;
    vector<vector<string>> subsets;
    path.clear();
    subsets.clear();
    backtracking4(strs, 0,path,subsets);
    cout<<"总有 "<<subsets.size()<<" 子集"<<endl;
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << "\"" << subset[i] << "\"";
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    for(int i=0;i<subsets.size();i++)
    {
        int onesum = 0;
        int zerosum = 0;
        for(int j = 0;j<subsets[i].size();j++)
        {
            // 字符串
            for(int k = 0;k<subsets[i][j].size();k++)
            {
                // 字符
                if(subsets[i][j][k]=='1')
                {
                    onesum++;
                }
                else
                {
                    zerosum++;
                }

            }
        }

        if(zerosum<=m&&onesum<=n)
        {
            result = result>subsets[i].size()?result: subsets[i].size();
        }

    }
}

// 动态规划版本
int DynamicProgramming_exp3(vector<string> &strs, int m,int n)
{
    vector< vector<int> > dp(m+1,vector<int>(n+1,0));  // 默认初始化为0

    for(string str:strs)
    {
        int oneNum = 0,zeroNum = 0;
        for (char c:str)
        {
            if(c=='0') zeroNum++;
            else
                oneNum++;
        }
        for(int i = m;i>=zeroNum;i--)
        {
            for(int j = n;j>=oneNum;j--)
            {
                dp[i][j] = max(dp[i][j],dp[i-zeroNum][j-oneNum]+1);
            }
        }
    }

    return dp[m][n];
}


