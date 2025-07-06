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
        backtracking_exp1(weight, value, maxweight, currentweight+weight[i], currentvlaue+value[i], maxvalue);
    }
}
