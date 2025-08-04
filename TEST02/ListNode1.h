#include <unordered_map>
using namespace std;
/*
时间:20250802 18:41
141. 环形链表
简单
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
bool hasCycle_bf(ListNode *head)
{
    // 统计节点个数：
    int num = 0;
    ListNode *cur = head;
    if (!cur)
        return false;
    while (cur)
    {
        num++;
        cur = cur->next;
        if (!cur)
            return false;
        if (num > 10000)
            break; // 10000参考 题目节点数范围得出
    }
    return true;
}

bool hasCycle_hash(ListNode *head)
{
    unordered_map<ListNode *, int> mp;
    ListNode *cur = head; // 游走节点
    while (cur)
    {
        if (mp[cur])
        {
            return true;
        }
        mp[cur]++;
        cur = cur->next;
    }
    return false;
}

bool hasCycle_doublepoints(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

/*
时间:20250803 19:28
142. 环形链表 II
中等
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。
*/
ListNode *detectCycle_hash(ListNode *head)
{
    unordered_map<ListNode *, int> mp;
    ListNode *cur = head;
    while (cur)
    {
        if (mp[cur])
            return cur;
        mp[cur]++;
        cur = cur->next;
    }
    return nullptr;
}
ListNode *detectCycle_doublepoints(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *ptr = head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (1)
    {
        if (!fast || !fast->next)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    while (ptr != slow)
    {
        ptr = ptr->next;
        slow = slow->next;
    }
    return ptr;
}
/*
时间:20250802 15:21
160. 相交链表
简单
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
图示两个链表在节点 c1 开始相交：
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(0), next(next) {};
// };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // 统计节点
    int numA = 0;
    int numB = 0;

    ListNode *cur = headA;
    while (cur)
    {
        numA++;
        cur = cur->next;
    }
    cur = headB;
    while (cur)
    {
        numB++;
        cur = cur->next;
    }
    //
    cur = headA;
    ListNode *curB = headB;

    int intervaln = abs(numA - numB);
    if (numA > numB)
    {
        while (intervaln > 0)
        {
            cur = cur->next;
            intervaln--;
        }
    }
    else
    {
        while (intervaln > 0)
        {
            curB = curB->next;
            intervaln--;
        }
    }

    while (cur && curB && cur != curB)
    {
        cur = cur->next;
        curB = curB->next;
    }
    if (!cur || !curB)
        return nullptr;
    return cur;
}

/*
时间:20250802 14:36
19. 删除链表的倒数第 N 个结点
已解答
中等
提示
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(x), next(next) {};
// };

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 统计节点个数
    int num = 0;
    ListNode *dummy = new ListNode(0); // 设置虚拟节点
    dummy->next = head;
    ListNode *cur = dummy->next; // 设置游走指针
    while (cur)
    {
        num++;
        cur = cur->next;
    }
    // 删除节点的下标 0 1 2 3 ....
    int index = num - n;
    cur = dummy;
    while (index > 0)
    {
        cur = cur->next;
        index--;
    }
    ListNode *tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    tmp = nullptr;

    // 输出
    head = dummy->next;
    delete dummy;
    dummy = nullptr;
    cur = nullptr;

    return head;
}

/*
时间:20250802 13:44
24. 两两交换链表中的节点
中等
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(x), next(next) {};
// };

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0); // 设置虚拟节点
    dummy->next = head;
    ListNode *pre = dummy;     // 设置游走指针
    ListNode *cur = pre->next; // 设置游走指针
    while (cur && cur->next)
    {
        // cur 和 cur->next交换位置
        // 把 cur->next 放到 cur 的位置
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        tmp->next = cur;
        pre->next = tmp;
        // 交换完成,下一次交换准备
        pre = cur;
        cur = cur->next;
    }

    head = dummy->next;
    delete dummy;
    return head;
}

/*
时间:20250802 10:52
206. 反转链表
简单
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(0), next(next) {};
// };

ListNode *reverseList(ListNode *head)
{
    ListNode *dummy = new ListNode(0); // 虚拟节点
    dummy->next = head;
    ListNode *cur = dummy->next; // 游走节点

    while (cur && cur->next)
    {
        ListNode *tmp1 = dummy->next; // dummy后面的节点 ,需要最后的位置
        ListNode *tmp2 = cur->next;   // 需要移动的位置
        cur->next = tmp2->next;
        dummy->next = tmp2;
        tmp2->next = tmp1;
    }

    head = dummy->next;
    delete dummy;
    return head;
}

/*
时间:20250801 19:56
707. 设计链表
中等
你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
实现 MyLinkedList 类：
MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(x), next(next) {};
// };

class MylinkNode
{
private:
public:
    ListNode *head;
    MylinkNode()
    {
        head = new ListNode(); //  初始化
    }

    int get(int index)
    {
        if (!head)
            return -1;
        // 返回下标
        ListNode *cur = head;

        // 下标0 1 2 3 4 5 6 7 8
        while (index > 0 && cur->next)
        {
            cur = cur->next;
            index--;
        }
        if (index != 0)
            return -1;
        return cur->val;
    }

    void addAtHead(int val)
    {
        // 头添加
        ListNode *tmp = new ListNode(val);
        tmp->next = head;
        head = tmp;
    }
    void addAtTail(int val)
    {
        ListNode *tmp = new ListNode(val);
        // 尾添加
        if (!head)
        {
            head = tmp;
        }
        ListNode *cur = head;

        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        // delete cur;
    }

    void addAtIndex(int index, int val)
    {
        // 在下标位置index 增加 节点
        ListNode *tmp = new ListNode(val);
        // 下标0 1 2 3 4 5 6 7 8
        if (!head)
            return;
        ListNode *cur = head;
        while (index > 1 && cur->next)
        {
            cur = cur->next;
            index--;
        }
        if (index != 1)
            return;
        tmp->next = cur->next;
        cur->next = tmp;
        // delete cur;
    }

    void deleteAtIndex(int index)
    {
        if (!head)
            return;
        ListNode *cur = head;
        while (index > 1 && cur->next)
        {
            cur = cur->next;
            index--;
        }
        if (index != 1) // 无效
            return;
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // delete cur;
    }

    ~MylinkNode()
    {
        // 删除链表
        while (head)
        {
            ListNode *tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
};

/*
时间:20250801 16:47
203. 移除链表元素
简单
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {};
//     ListNode(int x) : val(x), next(nullptr) {};
//     ListNode(int x, ListNode *next) : val(x), next(next) {};
// };

// 如果只是为了删除链表节点，不需要 new，只要把指针拿来 delete 就行。
ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    // 定义个先指针
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *pre = dummy;
    while (pre->next)
    {
        if (pre->next->val == val)
        {
            ListNode *temp = pre->next;
            pre->next = pre->next->next;
            delete temp;
        }
        else
        {
            pre = pre->next;
        }
    }

    // 3) 取出新的头节点，释放 dummy
    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}
