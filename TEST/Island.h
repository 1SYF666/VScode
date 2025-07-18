#include <vector>
using namespace std;

/*
200. 岛屿数量
中等
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/

// 图论法
static void BFS(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid)
{
    visited[x][y] = true;
    // 上
    if (x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y])
    {
        BFS(x - 1, y, visited, grid);
    }
    // 下
    if (x + 1 < grid.size() && grid[x + 1][y] == '1' && !visited[x + 1][y])
    {
        BFS(x + 1, y, visited, grid);
    }
    // 左
    if (y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1])
    {
        BFS(x, y - 1, visited, grid);
    }
    // 右
    if (y + 1 < grid[0].size() && grid[x][y + 1] == '1' && !visited[x][y + 1])
    {
        BFS(x, y + 1, visited, grid);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                count++;
                BFS(i, j, visited, grid);
            }
        }
    }

    return count;
}
