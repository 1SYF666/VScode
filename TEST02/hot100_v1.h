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
