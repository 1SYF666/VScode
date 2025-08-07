#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
时间:20250807 16:01
438. 找到字符串中所有字母异位词
已解答
中等
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
*/

vector<int> findAnagrams(string s, string t)
{
    vector<int> result;
    int n = s.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }

    // 滑动窗口状态: 存在某个字符数量大于t中对应的字符
    // [left right] 满足状态，[left,right+1]一定满足 状态
    // [left right] 不满足状态，[left+1,right]一定不满足 状态
    for (int left = 0, right = 0; right < n; right++)
    {
        mp[s[right]]--;
        while (mp[s[right]] < 0)
        {
            // 满足状态
            mp[s[left]]++;
            left++;
        }
        // 不满足状态
        if (right - left + 1 == t.size())
        {
            result.push_back(left);
        }
    }
    return result;
}

/*
时间:20250807 14:57
3. 无重复字符的最长子串
已解答
中等
提示
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
*/
int lengthOfLongestSubstring(string s)
{
    /*
[left,right] 没有重复，那么 [left+1,right]一定没有重复
[left,right] 有重复，那么 [left,right+1]一定有重复
*/
    int left = 0;
    int right = 0;
    int n = s.size();
    unordered_map<char, int> mp;
    int ans = 0;
    for (left = 0, right = 0; right < n; right++)
    {
        mp[s[right]]++;
        while (mp[s[right]] > 1)
        {
            // 重复
            mp[s[left]]--;
            left++;
        }
        // 不重复
        ans = max(ans, right - left + 1);
    }
    return ans;
}

static bool isRepeat(string s, int st, int end)
{
    unordered_set<char> hash;
    for (int i = st; i <= end; i++)
    {
        if (hash.find(s[i]) != hash.end())
        {
            // 重复
            return true;
        }
        hash.insert(s[i]);
    }
    return false;
}

int lengthOfLongestSubstring_v1(string s)
{
    /*
    [left,right] 没有重复，那么 [left+1,right]一定没有重复
    [left,right] 有重复，那么 [left,right+1]一定有重复
    */
    int n = s.size();
    int left = 0;
    int right = 0;
    int result = 0;
    while (right < n)
    {
        while (left <= right && isRepeat(s, left, right))
        {
            // 重复
            left++;
        }
        result = max(result, right - left + 1);
        right++;
    }
    return result;
}

struct DListNode
{
    int key, value;
    DListNode *prev;
    DListNode *next;
    DListNode() : key(0), value(0), prev(nullptr), next(nullptr) {};
    DListNode(int _key, int _value) : key(-_key), value(_value), prev(nullptr), next(nullptr) {};
};

class LRUCache
{
private:
    unordered_map<int, DListNode *> cache;
    DListNode *head;
    DListNode *tail;
    int size;
    int capacity;
};
