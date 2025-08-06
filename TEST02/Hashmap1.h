#include <string>
#include <unordered_map>
#include <unordered_set>
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

/*
时间:20250806 10:05
49. 字母异位词分组
已解答
中等
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
*/

static bool isAnagramself(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (mp[t[i]] == 0)
        {
            return false;
        }
        mp[t[i]]--;
    }
    return true;
}
// 超出时间限制
vector<vector<string>> groupAnagrams_bf(vector<string> &strs)
{
    vector<vector<string>> result;
    for (auto s : strs)
    {
        int i = 0;
        for (i = 0; i < result.size(); i++)
        {
            if (isAnagramself(s, result[i][0]))
            {
                // 存在 添加
                result[i].push_back(s);
                break;
            }
        }
        if (i == result.size())
        {
            result.push_back({s});
        }
    }
    return result;
}

/*
128. 最长连续序列
已解答
中等
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> hash;
    for (auto num : nums)
    {
        hash.insert(num);
    }
    int maxlen = 0;
    for (auto x : hash)
    {
        /*是否是开始值*/
        if (hash.count(x - 1) == 0)
        {
            // 是
            int currentnum = x;
            int currentlen = 1;
            while (hash.count(currentnum + 1))
            {
                currentnum++;
                currentlen++;
            }
            maxlen = maxlen > currentlen ? maxlen : currentlen;
        }
        // else
        // {
        //     // 不是
            
        // }
    }
    return maxlen;
}
