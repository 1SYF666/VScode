#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

/*
时间: 20250703 14:45
    739.每日温度
    给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
    其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
    如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/

// 暴力法 -- 超出时间限制
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> answer(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size() - 1; i++)
    {
        int flag = 1;
        for (int j = i + 1; j < temperatures.size(); j++)
        {
            if (temperatures[j] > temperatures[i])
            {
                flag = 0;
                answer[i] = (j - i);
                break;
            }
        }

        if (flag)
            answer[i] = 0;
    }
    return answer;
}

vector<int> dailyTemperatures_stack(vector<int> &temperatures)
{
    vector<int> answer(temperatures.size(), 0);
    stack<int> st;
    st.push(0); // 第一个入栈
    for (int i = 1; i < temperatures.size(); i++)
    {
        if (temperatures[i] <= temperatures[st.top()])
        {
            st.push(i);
        }
        else
        {
            while (st.size() && temperatures[i] > temperatures[st.top()])
            {
                answer[st.top()] = i - st.top();
                st.pop(); // 出
            }
            st.push(i); // 入
        }
    }

    return answer;
}

/*
时间: 20250705 14:59
    221.最大正方形
    在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
*/

// 暴力法
int MaximalSquare(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int th = row < col ? row : col;
    int result = 0;
    for (int step = 1; step <= th; step++)
    {
        
        int flag = 0;
        // 正方形尺寸
        for (int i = 0; i < matrix.size() - step + 1; i++)
        {
            for (int j = 0; j < matrix[0].size() - step + 1; j++)
            {
                int onesum = 0;
                // 统计正方形
                for (int krow = 0; krow < step; krow++)
                {
                    for (int kcol = 0; kcol < step; kcol++)
                        if (matrix[i + krow][j + kcol] == '1')
                            onesum++;
                }
                if (onesum == step * step)
                {
                    result = step*step;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    return result;
}
