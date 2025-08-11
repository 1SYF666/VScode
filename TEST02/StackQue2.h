#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
84. 柱状图中最大的矩形
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
// 90 / 99 
int largestRectangleArea_bf(vector<int> &heights)
{
    int n = heights.size();
    int res = 0;
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        sum = heights[i];
        temp = heights[i];
        for (int j = i + 1; j < n; j++)
        {
            temp = min(temp, heights[j]);
            sum = max(sum, temp * (j - i + 1));
        }
        res = max(sum, res);
    }
    return res;
}

/*
时间:20250811 11:21
739. 每日温度
已解答
中等
相关标签
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/
// 单调栈
// 方法：转化为 右边比当前值大 且最接近的值
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    if (n == 1)
        return res;
    //
    stack<int> st;  // 存放下标 ,对应值单减
    st.push(n - 1); // 最右边数组的下标
    //
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()])
        {
            st.pop();
        }
        res[i] = st.empty() ? 0 : st.top() - i;
        st.push(i);
    }
    return res;
}

// 47 / 48
vector<int> dd(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temperatures[j] > temperatures[i])
            {
                res[i] = j - i;
                break;
            }
        }
    }
    return res;
}

/*
时间:20250810 14:31
347. 前 K 个高频元素
中等
相关标签
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second; // 从大到小
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<pair<int, int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), cmp);
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(vec[i].first);
    }
    return res;
}

/*
时间:20250810 13:13
150. 逆波兰表达式求值
中等
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。
*/
int evalRPN(vector<string> &tokens)
{
    stack<long long> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            long long num2 = st.top();
            st.pop();
            long long num1 = st.top();
            st.pop();
            if (tokens[i] == "+")
                st.push(num1 + num2);
            if (tokens[i] == "-")
                st.push(num1 - num2);
            if (tokens[i] == "*")
                st.push(num1 * num2);
            if (tokens[i] == "/")
                st.push(num1 / num2);
        }
        else
        {
            st.push(stoll(tokens[i]));
        }
    }
    return st.top();
}

static long long strTodecimal(string s1)
{
    long long decimals1 = 0;
    int temp = 1;

    for (int k = s1.size() - 1; k >= 1; k--)
    {
        decimals1 += (s1[k] - '0') * temp;
        temp *= 10;
    }

    if (s1[0] == '-')
    {
        // 负数
        decimals1 *= -1;
    }
    else
    {
        decimals1 += (s1[0] - '0') * temp;
    }

    return decimals1;
}
// 通过率14 / 21
int evalRPN_error(vector<string> &tokens)
{
    stack<string> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            string sres = "";
            // 出栈
            if (!st.empty() && st.size() >= 2)
            {
                // 不为空
                string s2 = st.top();
                st.pop();
                string s1 = st.top();
                st.pop();
                // 转为整数
                long long decimals1 = strTodecimal(s1);
                long long decimals2 = strTodecimal(s2);

                long long res = 0;
                if (tokens[i] == "+")
                {
                    res = decimals1 + decimals2;
                }
                else if (tokens[i] == "-")
                {
                    res = decimals1 - decimals2;
                }
                else if (tokens[i] == "*")
                {
                    res = decimals1 * decimals2;
                }
                else
                {
                    res = decimals1 / decimals2;
                }
                // 转为字符串
                if (res != 0)
                {
                    while (res)
                    {
                        int remain = res % 10;
                        sres += (char)(remain + '0');
                        res = res / 10;
                    }
                    reverse(sres.begin(), sres.end());
                }
                else
                {
                    sres += '0';
                }
            }
            // 入栈
            st.push(sres);
        }
        else
        {
            // 入栈
            st.push(tokens[i]);
        }
    }

    string s2 = st.top();
    st.pop();
    long long result = 0;
    int temp = 1;
    for (int k = s2.size() - 1; k >= 0; k--)
    {
        result += (s2[k] - '0') * temp;
        temp *= 10;
    }
    return result;
}
