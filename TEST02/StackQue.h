#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

/*
时间:20250808 16:11
394. 字符串解码
中等
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
测试用例保证输出的长度不会超过 105。
*/
string decodeString(string s)
{
    stack<char> st1; //
    stack<char> st2; // 扩展

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ']')
        {
            st1.push(s[i]);
        }
        else
        {
            //      2 [ a b c
            // 此时s[i] == ']'
            while (st1.top() != '[')
            {
                st2.push(st1.top()); // c b a
                st1.pop();
            }
            // 此时 st1.top()=='['
            st1.pop();

            // // 此时 st1.top() == 'k'
            // int k = st1.top() - '0';
            // st1.pop(); //  把数字也去掉了
            // 可能有 111[abc].k不仅只小于10
            string ktemp = "";
            while (!st1.empty()&&st1.top() >= '0' && st1.top() <= '9')
            {
                ktemp += st1.top();
                st1.pop();
            }
            int k = 0;
            int kk = 1;
            for (int j = 0; j < ktemp.size(); j++)
            {
                if (j != 0)
                {
                    kk = kk * 10;
                }
                k += (ktemp[j] - '0') * kk;
            }

            // 重新压入到st1中
            string temp = "";
            while (!st2.empty())
            {
                temp += st2.top(); // a b c
                st2.pop();
            }
            while (k > 0)
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    st1.push(temp[i]); // a b c a b c
                }
                k--;
            }
        }
    }
    string result = "";
    while (!st1.empty())
    {
        // 不为空
        result += st1.top();
        st1.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

/*
时间:20250808 15:37
155. 最小栈
中等
提示
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/
class MinStack
{
private:
    stack<int> st1; // 相当于栈
    stack<int> st2; // 存放最小值 --- 单减 的stack

public:
    MinStack()
    {
    }
    void push(int val)
    {
        st1.push(val);
        if (st2.empty())
        {
            st2.push(val);
        }
        else
        { // 不为空
            if (val <= st2.top())
            {
                st2.push(val);
            }
        }
    }
    void pop()
    {
        if (!st2.empty() && st1.top() == st2.top())
        {
            st2.pop();
        }
        st1.pop();
    }
    int top()
    {
        return st1.top();
    }
    int getMin()
    {
        return st2.top();
    }
};

/*
时间:20250808 14:35
225. 用队列实现栈
简单
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
*/

class Mystack
{
private:
    queue<int> que1; // 入队列
    queue<int> que2; // 出队列

public:
    void push(int x)
    {
        //
        que1.push(x);
    }

    int pop()
    {
        // 移除并返回栈顶元素。
        if (!que1.empty())
        {
            // 不为空
            while (que1.size() != 1)
            {
                que2.push(que1.front());
                que1.pop();
            }
            int ans = que1.front();
            que1.pop();
            return ans;
        }
        else
        {
            // 为空
            while (que2.size() != 1)
            {
                que1.push(que2.front());
                que2.pop();
            }
            int ans = que2.front();
            que2.pop();
            return ans;
        }
    }

    int top()
    {
        int ans = this->pop();
        this->push(ans);
        return ans;
    }
    bool empty()
    {
        return que1.empty() && que2.empty();
    }
};

/*
232. 用栈实现队列
简单
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
*/

class MyQueue
{
private:
    stack<int> st1; //  用来 压
    stack<int> st2; // 用来 出
public:
    void push(int x)
    {
        st1.push(x);
    }
    int pop()
    {
        if (!st2.empty())
        {
            // st2 不为空
        }
        else
        {
            while (!st1.empty())
            {
                // st1 不为空
                st2.push(st1.top());
                st1.pop();
            }
        }
        int quefont = st2.top();
        st2.pop();
        return quefont;
    }
    int peek() // 返回队列开头的元素
    {
        int res = this->pop();
        st2.push(res);
        return res;
    }
    bool empty() // 如果队列为空，返回 true ；否则，返回 false
    {
        if (st1.empty() && st2.empty())
            return true;
        return false;
    }
};
