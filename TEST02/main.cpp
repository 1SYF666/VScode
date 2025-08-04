#include <iostream>
#include <vector>
#include"ListNode1.h"
using namespace std; 

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

int main()
{
    // 第一行节点个数
    // 第二行各节点值
    // 第三行返回各节点值
    // 1
    int n; // 节点数
    if (!(cin >> n))
        return 0;
    // 2
    vector<int> a(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 构建链表
    ListNode *dummy = new ListNode(0); // 虚拟节点
    ListNode *cur = dummy;             //  游走指针
    int i = 0;
    while (i < n)
    {
        //
        ListNode *node = new ListNode(a[i]);
        cur->next = node;
        // 增加完成
        cur = cur->next;
        i++;
    }
    ListNode *head = dummy->next;
    delete dummy;
    dummy = nullptr;
    // 调用函数
    ListNode *newHead = removeNthFromEnd(head,1);

    // 打印
    cur = newHead;
    cout << "[";
    bool fast = true;
    while (cur)
    {
        if (!fast)
            cout << ",";
        cout << cur->val;
        // 处理完
        cur = cur->next;
        fast = false;
    }
    cout << "]";

    // 释放内存
    while (newHead)
    {
        ListNode *tmp = newHead;
        newHead = newHead->next;
        delete tmp;
        tmp = nullptr;
    }
    cur =nullptr;
    return 0;
}
