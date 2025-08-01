

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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

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
        //delete cur;
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
        //delete cur;
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
        //delete cur;
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
