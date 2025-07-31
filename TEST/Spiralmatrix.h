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
        if(up>down) break;
        // 右
        for (int i = up; i <= down; i++)
        {
            matrix[i][right] = ++cnt;
        }
        right--;
        if(right<left) break;
        // 下
        for (int i = right; i >= left; i--)
        {
            matrix[down][i] = ++cnt;
        }
        down--;
        if(down<up) break;
        // 左
        for (int i = down; i >= up; i--)
        {
            matrix[i][left] = ++cnt;
        }
        left++;
        if(left>right) break;
    }
    return matrix;
}
