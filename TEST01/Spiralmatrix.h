#include <vector>
using namespace std;

/*
时间:20250731 19:36
54. 螺旋矩阵
已解答
中等
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

vector<int> spiralQrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();
    int up = 0, right = col - 1, down = row - 1, left = 0;
    while (1)
    {
        // 上
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[up][i]);
        }
        up++;
        if (up > down)
            break;
        // 右
        for (int i = up; i <= down; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (right < left)
            break;
        // 下
        for (int i = right; i >= left; i--)
        {
            result.push_back(matrix[down][i]);
        }
        down--;
        if (down < up)
            break;

        // 左
        for (int i = down; i >= up; i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
        if (left > right)
            break;
    }
    return result;
}

/*
时间:20250731 20:06
59. 螺旋矩阵 II
已解答
中等
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

vector<vector<int>> generatematrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int up = 0, right = n - 1, down = n - 1, left = 0;
    int cnt = 0;
    while (1)
    {
        // 上
        for (int i = left; i <= right; i++)
        {
            matrix[up][i] = ++cnt;
        }
        up++;
        if (up > down)
            break;
        // 右
        for (int i = up; i <= down; i++)
        {
            matrix[i][right] = ++cnt;
        }
        right--;
        if (right < left)
            break;
        // 下
        for (int i = right; i >= left; i--)
        {
            matrix[down][i] = ++cnt;
        }
        down--;
        if (down < up)
            break;
        // 左
        for (int i = down; i >= up; i--)
        {
            matrix[i][left] = ++cnt;
        }
        left++;
        if (left > right)
            break;
    }
    return matrix;
}

/*
时间:20250801 10:36
56. 合并区间
已解答
中等
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/

static bool cmp(vector<int> &a, vector<int> b)
{
    return a[0] < b[0];
}
#include <algorithm>
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    int n = intervals.size();
    // 排序 从小到大
    sort(intervals.begin(), intervals.end(), cmp);
    vector<int> path(2, 0);
    path[0] = intervals[0][0];
    path[1] = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] > path[1])
        {
            //[1,2] [3,4]
            result.push_back(path);
            path[0] = intervals[i][0];
            path[1] = intervals[i][1];
        }
        else
        {
            // [1,2] [2,3]
            if (intervals[i][1] > path[1])
                // [1,2] [2,3]
                path[1] = intervals[i][1];
            else
                // [1,2] [2,1]
                path[1] = path[1];
        }
    }
    result.push_back(path);
    return result;
}
// optomize version
vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    return result;
}

/*
时间:20250801 11:15
189. 轮转数组
中等
提示
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/
// 超出时间：38 / 39
vector<int> rotate_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    int temp = 0;
    for (int i = 1; i <= k; i++)
    {
        temp = nums[n - 1];
        for (int j = n - 1; j >= 1; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
    return nums;
}
static void swapself(vector<int> &nums, int st, int end)
{
    int temp = nums.size();
    while (st <= end)
    {
        temp = nums[st];
        nums[st] = nums[end];
        nums[end] = temp;
        st++;
        end--;
    }
}
vector<int> rotate_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    swapself(nums, 0, n - 1);
    swapself(nums, 0, k - 1);
    swapself(nums, k, n - 1);
    return nums;
}

/*
时间:20250801 15:03
41. 缺失的第一个正数
困难
相关标签
premium lock icon
相关企业
提示
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/
#include <unordered_map>
int firstMissingPositive_bf(vector<int> &nums)
{
    int n = nums.size();
    int result = 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            mp[nums[i]]++;
    }

    for (int i = 0; i < mp.size(); i++)
    {
        if (mp[result])
        {
            result++;
        }
    }
    return result;
}

int firstMissingPositive_bf2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> vec(n, 0); // 存放1-n元素
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0 && nums[i] <= n)
        {
            vec[nums[i] - 1] = nums[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] > 0 && nums[i] <= n &&
               nums[i] != nums[nums[i] - 1])
        {
            // 交换
            int temp = nums[i];
            int index = nums[i] - 1;
            nums[i] = nums[index];
            nums[index] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}