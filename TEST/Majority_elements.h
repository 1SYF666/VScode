#include <vector>
#include <map>
using namespace std;
/*
时间: 20250712 16:27
169. 多数元素
简单
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

// 暴力法
int majorityelements_bt(vector<int> &nums)
{
    int threadhold = nums.size() / 2;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (++mp[nums[i]] > threadhold)
            return nums[i];
    }
    return -1;
}
// 暴力--存遍历
int majorityelements_bt2(vector<int> &nums)
{
    int count = 0;
    int threadhold = nums.size() / 2;
    for (int i = 0; i < nums.size(); i++)
    {
        count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > threadhold)
            return nums[i];
    }
    return -1; // 出现次数没有大于n/2 的数
}

// 投票方法 -- 次数必须大于50%
int majorityelements(vector<int> &nums)
{
    int winner = 0;
    int count = 0;
    winner = nums[0];
    count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == winner)
            count++;
        else if (count == 0)
        {
            count = 1;
            winner = nums[i];
        }
        else
        {
            count--;
        }
    }
    return winner;
}
