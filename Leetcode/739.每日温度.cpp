/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
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
};
// @lc code=end
