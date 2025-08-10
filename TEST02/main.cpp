#include <iostream>
#include <vector>
#include "ListNode1.h"
#include "StackQue.h"
#include "StackQue2.h"
using namespace std;

int main()
{
    vector<string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = evalRPN(s);

    cout << result;
    return 0;
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
