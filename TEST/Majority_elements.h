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

/*
时间: 20250714 14:29
213. 打家劫舍 II
中等
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额
*/
