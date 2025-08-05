#include <vector>
using namespace std;

/*
时间:20250805 15:43
25. K 个一组翻转链表
困难
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int _val) : val(_val), next(nullptr) {};
    ListNode(int _val, ListNode *_next) : val(0), next(_next) {};
};

static ListNode *reverselistslef(ListNode *head, int k)
{
    // 翻转链表，并返回翻转后链表对应的头节点
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur && k > 0)
    {
        //
        ListNode *tmp = cur->next;
        cur->next = prev;
        //
        prev = cur;
        cur = tmp;
        //
        k--;
    }
    // 翻转后对应的尾节点 就是head
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    dummy->next = head;

    ListNode *curfirst = head;
    ListNode *cursecond = head;
    int temp = k;
    while (curfirst)
    {
        while (cursecond && temp > 1)
        {
            cursecond = cursecond->next;
            temp--;
        }
        if (cursecond)
        {
            // 翻转
            ListNode *tmp = cursecond->next;
            cur->next = reverselistslef(curfirst, k);
            cur = curfirst;
            curfirst = tmp;
            cursecond = curfirst;
        }
        else
        {
            break;
        }
        temp = k;
    }
    cur->next = curfirst;
    return dummy->next;
}

/*
时间:20250805 16:34
23. 合并 K 个升序链表
困难
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

static ListNode *mergertowlist(ListNode *node1, ListNode *node2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *pre = dummy;

    while (node1 && node2)
    {
        if (node1->val > node2->val)
        {
            pre->next = node2;
            node2 = node2->next;
        }
        else
        {
            pre->next = node1;
            node1 = node1->next;
        }
        pre = pre->next;
    }
    pre->next = (node1 == nullptr) ? node2 : node1;

    return dummy->next;
}

ListNode *mergeKLists_v1(vector<ListNode *> &lists)
{
    // 法1：一个一个合并
    ListNode *head = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
        head = mergertowlist(head,lists[i]);
    }
    return head;
}