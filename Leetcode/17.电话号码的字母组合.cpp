/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
string str;
vector<string> result;
vector<string> res;
void backtracking(string digits,int startindex)
{
    // 终止条件
    if(str.size() == digits.size())
    {
        result.push_back(str);
        return;
    }
    // 单层逻辑
    for(int i = startindex;i<digits.size();i++)
    {
        for(int j = 0;j<res[i].size();j++)
        {
            str.push_back(res[i][j]);
            backtracking(digits,i+1);
            str.pop_back();
        }
    }
}

void transform(string digits)
{
    for(int i = 0;i<digits.size();i++)
    {
        if(digits[i] == '2')
        {
            res.push_back({"abc"});
        }
        else if(digits[i] == '3')
        {
            res.push_back({"def"});
        }
        else if(digits[i] == '4')
        {
            res.push_back({"ghi"});
        }
        else if(digits[i] == '5')
        {
            res.push_back({"jkl"});
        }
        else if(digits[i] == '6')
        {
            res.push_back({"mno"});
        }
        else if(digits[i] == '7')
        {
            res.push_back({"pqrs"});
        }
        else if(digits[i] == '8')
        {
            res.push_back({"tuv"});
        }
        else if(digits[i] == '9')
        {
            res.push_back({"wxyz"});
        }
    }
}


public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }
        transform(digits);
        backtracking(digits,0);
        return result;
        
    }
};
// @lc code=end

