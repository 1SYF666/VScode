#include <vector>
#include <list>
using namespace std;

void dfs_adjacent_matrix(const vector<vector<int>> &graph, int x, int n, vector<int> &path, vector<vector<int>> &result)
{
    // 当前遍历的节点x 到达节点n
    if (x == n)
    {
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (graph[x][i] == 1)
        {
            path.push_back(i);
            dfs_adjacent_matrix(graph, i, n, path, result);
            path.pop_back();
        }
    }
}

void dfs_adjacent_list(const vector<list<int>> &graph, int x, int n, vector<int> &path, vector<vector<int>> &result)
{
    // 当前遍历的节点x 到达节点n
    if (x == n)
    {
        result.push_back(path);
        return;
    }
    for (int i : graph[x])
    {
        path.push_back(i);
        dfs_adjacent_list(graph, i, n, path, result);
        path.pop_back();
    }
}