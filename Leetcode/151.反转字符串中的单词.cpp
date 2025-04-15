/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {

        // 删除多余空格
        removeExtraSpaces(s);
        // 反转整个字符串
        reverseString(s);
        // 反转单个字符串
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if(i == s.size()||s[i]==' ')
            {
                reverseString(s,start,i-1);
                start = i+1;
            }
        }
        
        return s;
    }
    void reverseString(string& s,int start,int end) {
        int left = start;
        int right = end;
        char temp = 0;
        while (left<right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left ++;
            right --;
        }
    }


    void reverseString(string& s) {
        int left = 0;
        int right = s.size()-1;
        char temp = 0;
        while (left<right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left ++;
            right --;
        }
    }
    // 版本二
    void removeExtraSpaces(string &s)
    {                 // 去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0; // 整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i)
        { //
            if (s[i] != ' ')
            { // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ')
                { // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小。
    }

};
// @lc code=end
