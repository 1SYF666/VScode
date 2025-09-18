#include <vector>
#include <list>
#include<iostream>
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


void graphacm_adjacentlist() 
{
    int n, m, s, t;
    cin >> n >> m;

    vector<list<int>> graph(n + 1); // 邻接表
    while (m--)
    {
        cin >> s >> t;
        // 使用邻接表，表示s->t 是相连的
        graph[s].push_back(t);
    }
    vector<int> path;
    vector<vector<int>> result;
    path.push_back(1);

    dfs_adjacent_list(graph, 1, n, path, result);
    // 输出结果
    if (result.size() == 0)
        cout << -1 << endl;
    for (auto a : result)
    {
        bool flag = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (!flag)
            {
                cout << " ";
            }
            cout << a[i];
            flag = false;
        }
        cout << endl;
    }
    return;
}

void Graphacm_adjacencymatrix()
{
    // n 为顶点数 m为边数
    int n, m, s, t;
    cin >> n >> m;

    // 节点编号从1到n,所以申请空间 n+1这么大的数组
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    while (m--)
    {
        cin >> s >> t;
        // 使用邻接矩阵，表示无线图，1 表示s 与 t 是相连的
        graph[s][t] = 1;
    }

    vector<int> path;           // 1节点到终点的路径
    vector<vector<int>> result; // 收集符合条件的路径

    path.push_back(1);                              // 无论什么路径已经是从0节点出发
    dfs_adjacent_matrix(graph, 1, n, path, result); // 开始遍历

    // 输出结果
    if (result.size() == 0)
        cout << -1 << endl;
    for (auto a : result)
    {
        bool flag = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (!flag)
            {
                cout << " ";
            }
            cout << a[i];
            flag = false;
        }
        cout << endl;
    }
    return;
}
