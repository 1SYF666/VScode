#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
时间:20250810 14:31
347. 前 K 个高频元素
中等
相关标签
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/
static bool cmp(pair<int,int> &a, pair<int,int>& b)
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
    vector<pair<int,int>> vec(mp.begin(),mp.end());

    sort(vec.begin(),vec.end(),cmp);
    vector<int> res;
    for(int i = 0;i<k;i++)
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
