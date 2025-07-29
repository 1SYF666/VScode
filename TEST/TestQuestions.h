#include <vector>
#include <deque>
using namespace std;
/*
时间：20250722 18:31
六一儿童节到了，爸爸送给儿子一盒进口糖果，但是儿子吃糖没有节制，出于对孩子身体健康的考虑，同时也是为了让孩子提高学习，爸爸想出这样的办法:
爸爸:我在圆形餐盘的边缘，摆放了几堆糖果，现在你进行相邻两堆糖果的合并，每合并一次得到一个分值，这个分值为此次合并糖果的个数和，直至将这些糖果合并成一堆，将合并过程中的得分加起来最大(M)，
这样你就可以得到最大分值五分之一的糖果(当分值是奇数时向下取整)，否则你只能得到你的计算结果的十分之一的糖果。
*/

// 长桌合并糖果
int distribution_table(vector<int> &nums)
{
    int n = nums.size();
    // 前缀和,用于O(1)求区间和
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + nums[i];
    }
    auto rangeSum = [&](int l, int r)
    {
        return pre[r + 1] - pre[l];
    };

    // dp[i][j] == 合并区间[i,j]的最大得分
    // 初始化dp[i][i] = 0(单堆不需要合并，得分0)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 枚举长度 len 从 2 到 n
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            int best = 0;
            int total = rangeSum(i, j);

            // 枚举最后一次合并点 K:先合并[i...k] 和[k+1...j]
            // 然后再把这两堆合并，得分 = dp[i][k] + dp[k+1][j] + total
            for (int k = i; k < j; k++)
            {
                best = max(best, dp[i][k] + dp[k + 1][j] + total);
            }
            dp[i][j] = best;
        }
    }
    return dp[0][n - 1];
}

// 圆桌合并糖果
int distributioncandy_roundtable(vector<int> &nums, int n)
{
    return 0;
}

/*
时间:20250728 16:07
239. 滑动窗口最大值
困难
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
*/
// 通过率：38/51
vector<int> maxSlidingWindow_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxtemp = INT32_MIN;
    vector<int> result;
    for (int i = 0; i < n - k + 1; i++)
    {
        maxtemp = INT32_MIN;
        for (int j = i; j < i + k; j++)
        {
            maxtemp = max(nums[j], maxtemp);
        }
        result.push_back(maxtemp);
    }
    return result;
}

struct MyQueue
{                   // 实现单调队列（从大到小）
    deque<int> que; // 使用deque来实现单调队列

    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出
    void pop(int value)
    {
        if (!que.empty() && value == que.front())
            que.pop_front();
    }
    // 如何push的数值大于入口元素的数值，那么就将队列后端的数值弹出
    // 直到push的数值小于等于队列入口,从队尾push
    void push(int value)
    {
        while (!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }

    // 查询当前队列里的最大值，直接返回队列前端 也就是front就可以了。
    int front()
    {
        return que.front();
    }
};

// 单调队列实现
vector<int> maxSlidingWindow_deque(vector<int> &nums, int k)
{
    MyQueue que;

    vector<int> result;

    for (int i = 0; i < k; i++)
    { // 先将前k的元素放入队列
        que.push(nums[i]);
    }

    result.push_back(que.front()); // 记录前k个元素的最大值

    for (int i = k; i < nums.size(); i++)
    {
        que.pop(nums[i-k]);  // 滑动窗口移除最前面元素
        que.push(nums[i]);  // 滑动窗口前加入最后面的元素
        result.push_back(que.front());  // 记录对应的最大值
    }
    return result;
}
