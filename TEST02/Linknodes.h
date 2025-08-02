
/*
时间:20250802 15:21
160. 相交链表
简单
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
图示两个链表在节点 c1 开始相交：
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(0), next(next) {};
};

static ListNode *reverseself(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy->next;
    // 翻转
    // 1 2 3 4
    // 4 3 2 1
    ListNode *pre = dummy->next;
    ListNode *late = cur->next;
    while (cur && cur->next)
    {
        pre = dummy->next;
        late = cur->next;
        cur->next = cur->next->next;
        dummy->next = late;
        late->next = pre;
    }
    ListNode* headA = dummy->next;
    delete dummy;
    dummy = nullptr;
    cur = nullptr;
    pre = nullptr;
    late = nullptr;
    return headA;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // 翻转链表
    ListNode *headA1 = reverseself(headA);
    ListNode *headB1 = reverseself(headB);
    ListNode *curA = headA1;
    ListNode *curB = headB1;
    ListNode *pre = curA;

    int flag = 0;
    while (curB && curA && curA->val == curB->val)
    {
        if (flag == 1)
            pre = pre->next;
        flag = 1;
        curA = curA->next;
        curB = curB->next;
    }
    if (flag == 0)
        return nullptr;
    return pre;
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
