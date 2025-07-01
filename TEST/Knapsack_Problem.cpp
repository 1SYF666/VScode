#include <vector>
#include <iostream>
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

void example1(int &finalvalue)
{
    // 物品:下标索引0 1 2
    int maxweight = 4;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int maxValue = 0;
    backtracking(0, 0, 0, maxweight, weight, value, maxValue);
    finalvalue = maxValue;
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
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    return dp[weight.size() - 1][maxweight];
}

int TestExample1()
{
    // int finalvalue = 0;
    // example1(finalvalue);
    int finalvalue = DynamicProgramming_exp1();
    cout << "最大价值是：" << finalvalue << endl;
    return 0;
}


int main()
{
    
    return 0;
}
