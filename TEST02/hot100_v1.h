#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> Leetcode1(vector<int> &nums, int target)
{
    /*
    <key,value>
    key 放元素
    value 放下标
    */
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {i, mp[target - nums[i]]};
        }
        mp[nums[i]] = i;
    }
    return {};
}
#include <algorithm>
//
vector<vector<string>> leetcode49(vector<string> &strs)
{
    /*
    排序
    */
    //
    unordered_map<string, vector<string>> mp;
    for (auto s : strs)
    {
        string temp = s;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(s);
    }
    // 输出
    vector<vector<string>> ans;
    for (auto m : mp)
    {
        ans.push_back(m.second);
    }
    return ans;
}
#include <unordered_set>
int leetcode128(vector<int> &nums)
{
    /*
        哈希表里面，存放值，
        序列长度：找到一个值，那么这个值下一个值在哈希表里，那么就是连续序列加一
        序列开头：找到一个值，如果这个值的上一个值不在哈希表里，那么就是序列开头
    */
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    int maxlen = 0;
    for (auto num : st)
    {
        if (st.find(num - 1) != st.end())
        {
            // 不是开头
            continue;
        }
        int curnum = num;
        int curlen = 1;
        while (st.find(curnum + 1) != st.end())
        {
            // 在
            curnum++;
            curlen++;
        }
        maxlen = max(maxlen, curlen);
    }

    return maxlen;
}

//
vector<int> leetcode283(vector<int> &nums)
{
    int slow = 0;
    int fast = 0;
    // 快慢指针
    while (fast < nums.size())
    {
        if (nums[fast] != 0)
        {
            int temp = nums[fast];
            nums[fast] = nums[slow];
            nums[slow] = temp;
            slow++;
        }
        fast++;
    }
    return;
}
//
int leetcode11(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int ans = 0;
    while (left < right)
    {
        int w = right - left;
        int h = min(height[left], height[right]);
        ans = max(ans, w * h);
        if (height[left] < height[right])
        {
            int lefttemp = height[left];
            while (left < right && height[left] <= lefttemp)
            {
                left++;
            }
        }
        else
        {
            int righttemp = height[right];
            while (left < right && height[right] <= righttemp)
            {
                right--;
            }
        }
    }
    return ans;
}

vector<vector<int>> leetcode15(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 从小到大

    for (int i = 0; i < n;)
    {
        if (nums[i] > 0)
        {
            break;
        }
        int left = i + 1;
        int right = n - 1;
        int twosum = 0 - nums[i];
        while (left < right)
        {
            int twosumtarget = nums[left] + nums[right];
            if (twosumtarget == twosum)
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                // 去重
                int temp = nums[left];
                while (left < right && nums[left] == temp)
                    left++;
                temp = nums[right];
                while (left < right && nums[right] == temp)
                    right--;
            }
            else if (twosumtarget > twosum)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        // 去重
        int temp = nums[i];
        while (i < n && nums[i] == temp)
        {
            i++;
        }
    }
    return ans;
}

#include <stack>
//
int leetcode42(vector<int> &height)
{
    // 单调栈 放下标
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int temp = st.top();
            st.pop();
            if (!st.empty())
            {
                int w = i - st.top() - 1;
                int h = min(height[i], height[st.top()]) - height[temp];
                ans += w * h;
            }
        }
        st.push(i);
    }
    return ans;
}

int leetcode3(string s)
{
    // 窗口状态：无重复子串
    // [left,right] 满足窗口状态，[left+1,right] 一定满足窗口状态
    // [left,right] 不满足窗口状态，[left,right+1] 一定不满足窗口状态
    int n = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    for (right = 0; right < n; right++)
    {
        mp[s[right]]++;
        while (mp[s[right]] > 1)
        {
            // 不满足状态
            mp[s[left]]--;
            left++;
        }
        // 满足状态

        ans = max(ans, right - left + 1);
    }
    return ans;
}

//
vector<int> leetcode438(string s, string p)
{
    vector<int> ans;
    // 窗口状态：存在某个字符数量大于p中的对应的字符
    unordered_map<char, int> mp;
    for (auto c : p)
    {
        mp[c]++;
    }
    int left = 0;
    int right = 0;
    for (right = 0; right < s.size(); right++)
    {
        mp[s[right]]--;
        while (mp[s[right]] < 0)
        {
            mp[s[left]]++;
            left++;
        }
        if ((right - left + 1) == p.size())
        {
            ans.push_back(left);
        }
    }
    return ans;
}

//
int leetcode560(vector<int> &nums, int k)
{
    int ans = 0;
    // 前缀和
    vector<int> pre(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        pre[i + 1] = pre[i] + nums[i];
    }
    unordered_map<int, int> mp;
    // key : 和
    // value:值
    for (int i = 0; i <= nums.size(); i++)
    {
        if (mp.count(pre[i] - k))
        {
            ans += mp[pre[i] - k];
        }
        mp[pre[i]]++;
    }
    return ans;
}
#include <deque>
vector<int> leetcode239(vector<int> &nums, int k)
{
    vector<int> ans;
    // 双向队列 (存放下标)
    // 大----------------小
    deque<int> q;
    for (int i = 0; i < nums.size(); i++)
    {
        // 出
        while (!q.empty() && i - q.front() >= k)
        {
            q.pop_front();
        }

        // 入
        while (!q.empty() && nums[i] > nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        // 输出结果
        if (i - k + 1 >= 0)
        {
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}

//
string leetcode76(string s, string t)
{
    // 窗口状态：覆盖子串t
    //[left,right] 满足这个状态，[left,right+1] 满足这个状态
    //[left,right] 不满足这个状态，[left+1,right] 满足这个状态
    unordered_map<char, int> mp;
    for (auto c : t)
    {
        mp[c]++;
    }
    int left = 0;
    int right = 0;
    int len = s.size();
    int l = 0;
    int r = s.size();
    int total = 0;
    for (right = 0; right < s.size(); right++)
    {
        mp[s[right]]--;
        if (mp[s[right]] >= 0)
        {
            total++;
        }
        while (total == t.size())
        {
            // 满足这个状态
            if (right - left < len)
            {
                len = right - left;
                l = left;
                r = right;
            }
            mp[s[left]]++;
            if (mp[s[left]] > 0)
            {
                total--;
            }
            left++;
        }
    }
    return r == s.size() ? "" : s.substr(l, r - l + 1);
}

//
int leetcode53(vector<int> &nums)
{
    // dp[i]表示[0,i]数组对应的最大子数组之和
    // dp[i] = max(dp[i-1]+nums[i],nums[i])
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

//
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
vector<vector<int>> leetcode56(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), cmp); // 从小到大
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

void swapself(vector<int> &nums, int l, int r)
{
    while (l <= r)
    {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
    return;
}
vector<int> leetcode189(vector<int> &nums, int k)
{
    k = k % nums.size();
    swapself(nums, 0, nums.size() - 1);
    swapself(nums, 0, k - 1);
    swapself(nums, k, nums.size() - 1);
    return nums;
}

vector<int> leetcode238(vector<int> &nums)
{
    // 前缀积和后缀积
    vector<int> pre(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        pre[i] = nums[i - 1] * pre[i - 1];
    }
    int temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i != nums.size() - 1)
        {
            temp *= nums[i + 1];
        }
        pre[i] *= temp;
    }
    return pre;
}
//
int leetcode41(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            int temp = nums[i];
            int index = nums[i] - 1;
            nums[i] = nums[index];
            nums[index] = temp;
        }
    }
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            break;
    }
    return i + 1;
}

vector<vector<int>> leetcode73(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> index;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                index.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < index.size(); i++)
    {
        int row = index[i][0];
        for (int j = 0; j < n; j++)
        {
            matrix[row][j] = 0;
        }

        int col = index[i][1];
        for (int i = 0; i < m; i++)
        {
            matrix[i][col] = 0;
        }
    }
}
