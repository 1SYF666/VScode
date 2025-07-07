#include <vector>
using namespace std;

/*
时间: 20250706 14:20
背包最大重量为4，物品为：
            重量	价值
物品0	    1	    15
物品1	    3	    20
物品2	    4	    30
每件商品都有无限个！
问背包能背的物品最大价值是多少？
*/

void backtracking_exp1(const vector<int> &weight, const vector<int> value, const int maxweight, int currentweight, int currentvlaue, int &maxvalue)
{
    // 终止条件
    if (currentweight > maxweight)
    {
        return;
    }
    maxvalue = max(currentvlaue, maxvalue);
    // 可以无限使用
    for (int i = 0; i < weight.size(); i++)
    {
        backtracking_exp1(weight, value, maxweight, currentweight + weight[i], currentvlaue + value[i], maxvalue);
    }
}

int DynamicProgramming_exp1(const vector<int> &weight, const vector<int> value, int n, const int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    // 初始化
    for (int j = 1; j <= maxweight; j++)
    {
        dp[0][j] = j / weight[0] * value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= maxweight; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j-weight[i]]+value[i]);
        }
    }
    return dp[n-1][maxweight];
}
