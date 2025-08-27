#include <iostream>
#include <vector>
#include <list>
#include "ListNode1.h"
#include "StackQue.h"
#include "StackQue2.h"
#include "Graph.h"
#include "BackTrack.h"
using namespace std;

int main()
{
    string s = "101023";
    IPaddress(s);
    return 0;
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

void acmlinknodes()
{
    int n;
    // 输入格式示例:
    // 第一行:链表节点个数n(0<n<10^4)
    // 第二行:n 个整数，表示链表的各节点值
    // 第三行:一个整数val,表示要删除的目标值

    if (!(cin >> n))
        return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int val;
    cin >> val;

    // 构建链表
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int x : a)
    {
        ListNode *node = new ListNode(x);
        if (!head)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // 调用删除函数
    ListNode *newHead = removeElements(head, val);

    // 输出结果: 按链表顺序打印所有节点值，空链表则输出空行
    cout << "[";
    bool first = true;
    for (ListNode *p = newHead; p; p = p->next)
    {
        if (!first)
            cout << ' ';
        first = false;
        cout << p->val;
    }
    cout << "]\n";

    // 清理链表内存
    while (newHead)
    {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }
    return;
}
