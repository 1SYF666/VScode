#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
时间:20250805 19:24
242. 有效的字母异位词
已解答
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
*/
bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (mp.count(t[i]) == 0)
        {
            return false;
        }
        else
        {
            mp[t[i]]--;
        }
    }
    int sum = 0;
    for (auto x : mp)
    {
        sum += x.second;
    }

    return (sum == 0) ? true : false;
}

/*
349. 两个数组的交集
已解答
简单
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums1.size(); i++)
    {
        mp[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (mp[nums2[i]] != 0)
        {
            result.push_back(nums2[i]);
            mp.erase(nums2[i]);
        }
    }
    return result;
}

/*
1. 两数之和
已解答
简单
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
*/

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}