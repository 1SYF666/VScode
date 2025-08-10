#include <unordered_map>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

vector<int> maxslidewindows(vector<int> &nums, int k)
{
    vector<int> result;
    // front 大 --- back 小
    deque<int> q;
    for (int i = 0; i < nums.size(); i++)
    {
        // 出--因为窗口长度就是k
        while (q.size() && q.front() == i - k)
        {
            q.pop_front();
        }

        // 从队尾入
        while (q.size() && nums[i] > nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        // 弹出
        if (i - k + 1 >= 0)
        {
            result.push_back(nums[q.front()]);
        }
    }
    return result;
}

/*
时间:20250807 18:29
76. 最小覆盖子串
困难
相关标签
提示
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/

string minWindow(string s, string t)
{
    int n = s.size();

    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }
    // 窗口状态：覆盖t中所有字符
    // [left right] 满足这个状态，[left,right+1]一定满足这个状态  left++
    // [left right] 不满足这个状态，[left+1,right]一定不满足这个状态

    int totalCnt = 0; // 窗口中有效字符数量
    int ans_left = 0, ans_right = s.size();

    for (int left = 0, right = 0; right < n; right++)
    {
        mp[s[right]]--;
        if (mp[s[right]] >= 0)
        {
            totalCnt++; // 窗口中字符有效
        }
        while (totalCnt == t.size())
        {
            // 满足状态
            if ((ans_right - ans_left) > (right - left))
            {
                ans_left = left;
                ans_right = right;
            }

            mp[s[left]]++;
            if (mp[s[left]] > 0)
            {
                totalCnt--;
            }
            left++;
        }
        // 不满足状态
    }
    return ans_right == s.size() ? "" : s.substr(ans_left, ans_right - ans_left + 1);
}

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
    DListNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {};
};

class LRUCache
{
private:
    unordered_map<int, DListNode *> cache;
    DListNode *head;
    DListNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        // 使用虚头部和虚尾部
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        // 不存在
        if (!cache.count(key))
        {
            return -1;
        }
        // 存在
        DListNode *node = cache[key];
        moveTohead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        // 存在
        if (!cache.count(key))
        {
            // 不存在
            // 插入
            DListNode *node = new DListNode(key, value);
            cache[key] = node;
            size++;
            // 添加至双向链表的头部
            addTohead(node);
            if (size > capacity)
            {
                // 判断是否 超容
                DListNode *remove = removeTail();
                // 是 删除尾部
                cache.erase(remove->key);
                delete (remove);
                --size;
                // 否  不管
            }
        }
        else
        {
            // 存在
            DListNode *node = cache[key];
            node->value = value;
            moveTohead(node);
        }
    }

    void moveTohead(DListNode *node)
    {
        // 从原始链表中移除掉  -- 保持链表节点节点之间稳定
        removeNode(node);
        // 把 该节点 放到头部
        addTohead(node);
    }

    void removeNode(DListNode *node)
    {
        // A-->B-->c
        // A<--B<--C
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addTohead(DListNode *node)
    {
        // head --> A
        // head <-- A
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
    }
    DListNode *removeTail()
    {
        // A-->tail
        // A<--tail
        DListNode *A = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = A->prev;
        return A;
    }
};
