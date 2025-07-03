#include <iostream>
#include <vector>
#include <stack>

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
            while (st.size()&&temperatures[i] > temperatures[st.top()])
            {
                answer[st.top()] = i - st.top();
                st.pop();   // 出
            }
            st.push(i); // 入
        }
    }

    return answer;
}

int main()
{
    vector<int> temperatures = {30, 60, 90};
    vector<int> answer = dailyTemperatures_stack(temperatures);
    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << endl;
    return 0;
}
