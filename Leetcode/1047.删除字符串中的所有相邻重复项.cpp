/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++)
        {
            if (!st.empty()&&s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string result= "";
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result);
        return result;
    }

    void reverse(string& s)
    {
        int left = 0;
        int right = s.size()-1;
        while (left<right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }



};
// @lc code=end

