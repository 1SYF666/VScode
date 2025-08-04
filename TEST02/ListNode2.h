#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
时间:20250804 14:31
21. 合并两个有序链表 --------巨难---- 后面再写
简单
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(0), next(next) {};
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // 都为空
    if (!list1 && !list2)
        return nullptr;
    // 一个为空
    if (!list1 || !list2)
        return (!list1) ? list2 : list1;

    // 都不为空
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;
    ListNode *head = (cur1->val > cur2->val) ? cur1 : cur2;

    while (cur1 && cur2)
    {
        // 1 2 4
        // 1 3 4
        // cur1 大
        if (cur1->val >= cur2->val)
        {
            if (cur2->next && cur1->val >= cur2->next->val)
            {
                cur2 = cur2->next;
            }
            else
            {
                ListNode *tmp2 = cur2->next;
                cur2->next = cur1;
                cur2 = tmp2;
            }
        }
        else
        {
            // cur1 小
            if (cur1->next && cur1->next->val >= cur2->val)
            {
                ListNode *tmp1 = cur1->next;
                cur1->next = cur2;
                cur1 = tmp1;
            }
            else
            {
                cur1 = cur1->next;
            }
        }
    }
    return head;
}

/*
时间:20250804 18:56
138. 随机链表的复制
中等
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
*/
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(nullptr), random(nullptr) {};
    Node(int val) : val(val), next(nullptr), random(nullptr) {};
};

Node *copyRandomListbf(Node *head)
{
    Node *dummy = new Node(0);
    Node *ptr = dummy;
    Node *cur = head;

    // 复制链表
    while (cur)
    {
        Node *tmp = new Node(cur->val);
        ptr->next = tmp;
        ptr = ptr->next;
        cur = cur->next;
    }
    cur = head;
    ptr = dummy->next;
    // 调整指针节点
    while (cur)
    {
        if (cur->random == nullptr)
        {
            ptr->random = nullptr;
        }
        else
        {
            Node *ptr2 = head;
            Node *t = dummy->next;
            while (ptr2 && ptr2 != cur->random)
            {
                ptr2 = ptr2->next;
                t = t->next;
            }
            ptr->random = t;
        }

        cur = cur->next;
        ptr = ptr->next;
    }
    return dummy->next;
}

/*
时间:20250804 19:58
148. 排序链表
中等
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/

ListNode *sortList_bf(ListNode *head)
{
    // 值存在数组中
    vector<int> temp;
    ListNode *ptr = head;
    while (ptr)
    {
        temp.push_back(ptr->val);
        ptr = ptr->next;
    }

    // 对数组排序
    sort(temp.begin(), temp.end());
    ListNode* dummy = new ListNode(0);
    ptr = dummy;
    // 构造链表
    for (int i = 0; i < temp.size(); i++)
    {
        ListNode *node = new ListNode(temp[i]);
        ptr->next = node;
        ptr = ptr->next;
    }
    return dummy->next;
}


/*
时间:20250804 20:31
146. LRU 缓存
中等
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/









/*
时间:20250804 16:07
2. 两数相加
已解答
中等
相关企业
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ptr1 = l1;
    ListNode *ptr2 = l2;

    ptr1 = l1;
    ptr2 = l2;
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int temp = 0;
    int t1 = 0;
    int t2 = 0;
    while (ptr1 || ptr2)
    {
        t1 = (ptr1) ? ptr1->val : 0;
        t2 = (ptr2) ? ptr2->val : 0;
        int temp2 = t1 + t2 + temp;
        temp = temp2 / 10;
        ListNode *node = new ListNode(temp2 % 10);
        cur->next = node;
        cur = node;
        if (ptr1)
            ptr1 = ptr1->next;
        if (ptr2)
            ptr2 = ptr2->next;
    }
    if (temp != 0)
    {
        ListNode *node = new ListNode(temp);
        cur->next = node;
        cur = node;
    }
    return dummy->next;
}

/*
时间:20250804 10:31
234. 回文链表
简单
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(x), next(next) {};
// };

bool isPalindromeList_bf(ListNode *head)
{
    int num = 0;
    if (!head)
        return false;
    vector<int> dp;
    while (head)
    {
        dp.push_back(head->val);
        head = head->next;
        num++;
    }
    for (int i = 0, j = num - 1; i <= j; i++, j--)
    {
        if (dp[i] != dp[j])
            return false;
    }
    return true;
}

static ListNode *reverselistself(ListNode *head)
{
    /*双指针法*/
    // 翻转链表
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur)
    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

static ListNode *endoffisthalf(ListNode *head)
{
    /*快慢指针*/
    // 返回后链表后半部分头节点
    // 1 2 3 4 5 —————— 返回 节点3地址
    // 1 2 3 4   —————— 返回 节点2地址
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindromeList_reverse(ListNode *head)
{
    // 找到后半部分开始前
    ListNode *firstHalfEnd = endoffisthalf(head);
    // 后半部分翻转后起始节点
    ListNode *secondHalfStart = reverselistself(firstHalfEnd->next);

    ListNode *pre = head;
    ListNode *cur = secondHalfStart;
    bool result = true;
    while (result && cur)
    {
        if (cur->val != pre->val)
        {
            result = false;
        }
        pre = pre->next;
        cur = cur->next;
    }
    // 恢复链表
    firstHalfEnd->next = reverselistself(secondHalfStart);

    return result;
}
