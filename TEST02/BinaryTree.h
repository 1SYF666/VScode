#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

/*
时间:20250812 15:26
515. 在每个树行中找最大值
中等
相关标签
premium lock icon
相关企业
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
*/
vector<int> largestValues(TreeNode *root)
{
    vector<int> vec;
    queue<TreeNode *> q;
    if (!root)
        return vec;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        int temp = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp = max(temp, node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        vec.push_back(temp);
    }
    return vec;
}

/*
时间:20250812 15:26
429. N 叉树的层序遍历
中等
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
*/

struct Node
{
    int val;
    vector<Node *> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> vec;
    queue<Node *> q;
    if (!root)
        return vec;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            temp.push_back(node->val);
            for (int k = 0; k < node->children.size(); k++)
            {
                if (node->children[k])
                    q.push(node->children[k]);
            }
        }
        vec.push_back(temp);
    }
    return vec;
}

vector<int> preorder_traversal(TreeNode *root)
{
    vector<int> vec;
    stack<TreeNode *> st;
    if (root == nullptr)
        return vec;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top(); // 中
        st.pop();
        vec.push_back(node->val);
        if (node->right)
            st.push(node->right); // 右
        if (node->left)
            st.push(node->left); // 左
    }
    return vec;
}

vector<int> inorder_traversal(TreeNode *root)
{
    vector<int> vec;
    stack<TreeNode *> st;
    if (root == nullptr)
        return vec;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left; // 左
        }
        else
        {
            cur = st.top(); // 中
            st.pop();
            vec.push_back(cur->val);
            cur = cur->right; // 右
        }
    }
    return vec;
}

// 左 右 中——————>中右左———————>中左右
vector<int> postorder_traversal(TreeNode *root)
{
    vector<int> vec;
    stack<TreeNode *> st;
    if (root == nullptr)
        return vec;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top(); // 中
        st.pop();
        vec.push_back(node->val);
        if (node->left)
            st.push(node->left); // 左
        if (node->right)
            st.push(node->right); // 右
    }
    reverse(vec.begin(), vec.end()); // 中右左——————>左右中
    return vec;
}
//
vector<int> level_order_traversal(TreeNode *root)
{
    vector<int> vec;
    queue<TreeNode *> q;
    if (root == nullptr)
        return vec;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        vec.push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    return vec;
}

vector<vector<int>> level_order_traversal_v2(TreeNode *root)
{
    vector<vector<int>> vec;
    queue<TreeNode *> q;
    if (root == nullptr)
        return vec;
    q.push(root);

    while (!q.empty())
    {
        //
        int n = q.size();
        vector<int> temp;
        while (n--)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        vec.push_back(temp);
    }
    return vec;
}
