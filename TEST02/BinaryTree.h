#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};


/*
时间:20250814 16:36
437. 路径总和 III
中等
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/
void dfspathsum3(TreeNode *root, long long targetSum, int &count)
{
    if (root == nullptr)
        return;
    targetSum -= root->val;
    if (targetSum == 0)
    {
        count++;
        dfspathsum3(root->left, targetSum, count);
        dfspathsum3(root->right, targetSum, count);
        return;
    }

    if (root->left)
    {
        dfspathsum3(root->left, targetSum, count);
    }
    if (root->right)
    {
        dfspathsum3(root->right, targetSum, count);
    }
}
int pathSum3_v2(TreeNode *root, int targetSum)
{
    int temp = 0;
    if (root == nullptr)
        return 0;
    dfspathsum3(root, targetSum, temp);
    int inorder = temp;
    int l = pathSum3_v2(root->left, targetSum);
    int r = pathSum3_v2(root->right, targetSum);
    return inorder + l + r;
}

void dfspathsum3(TreeNode *root, long long targetSum, int &count)
{
    if (root == nullptr)
        return;
    targetSum -= root->val;
    if (targetSum == 0)
    {
        count++;
        dfspathsum3(root->left, targetSum, count);
        dfspathsum3(root->right, targetSum, count);
        return;
    }

    if (root->left)
    {
        dfspathsum3(root->left, targetSum, count);
    }
    if (root->right)
    {
        dfspathsum3(root->right, targetSum, count);
    }
}

int pathSum3(TreeNode *root, int targetSum)
{
    int result = 0;
    if (root == nullptr)
    {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            dfspathsum3(node, (long long)targetSum, result);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return result;
}

/*
时间:20250814 16:36
113. 路径总和 II
已解答
中等
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
*/
void dfspathsum2(TreeNode *root, int targetSum, vector<int> &temp, vector<vector<int>> &result)
{
    if (root == nullptr)
        return;
    targetSum -= root->val;
    temp.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum == 0)
        {
            result.push_back(temp);
            return;
        }
        return;
    }
    if (root->left)
    {
        dfspathsum2(root->left, targetSum, temp, result);
        temp.pop_back();
    }
    if (root->right)
    {
        dfspathsum2(root->right, targetSum, temp, result);
        temp.pop_back();
    }
}
vector<vector<int>> pathSum2(TreeNode *root, int targetSum)
{
    vector<int> path;
    vector<vector<int>> result;
    dfspathsum2(root, targetSum, path, result);
    return result;
}

/*
时间:20250814 16:23
112. 路径总和
已解答
简单
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
*/

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    // 退出
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum == 0)
        {
            return true;
        }
        else
            return false;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

/*
时间:20250813 11:14
513. 找树左下角的值
已解答
中等
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
*/
// 层序遍历
int findBottomLeftValue(TreeNode *root)
{

    queue<TreeNode *> que;
    if (root != NULL)
        que.push(root);
    int result = 0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (i == 0)
                result = node->val; // 记录最后一行第一个元素
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return result;
}

/*
时间:20250813 10:36
404. 左叶子之和
已解答
简单
给定二叉树的根节点 root ，返回所有左叶子之和。
*/

// 左右中
int sumOfLeftLeaves(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 0;
    int l = sumOfLeftLeaves(root->left);

    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
        l = root->left->val;
    }

    int r = sumOfLeftLeaves(root->right);
    return l + r;
}

int sumOfLeftLeaves_iterative(TreeNode *root)
{
    int ans = 0;
    if (!root)
        return 0;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
        {
            ans += node->left->val;
        }
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return ans;
}

/*
时间:20250813 15:35
257. 二叉树的所有路径
已解答
简单
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。
*/
void dfs(TreeNode *root, string &res, vector<string> &result)
{
    if (root == nullptr)
    {
        return;
    }
    if (res.size())
    {
        res += "->";
        res += to_string(root->val);
    }
    else
    {
        res += to_string(root->val);
    }
    if (!root->left && !root->right)
    {
        result.push_back(res);
        return;
    }
    if (root->left)
        dfs(root->left, res, result);
    if (root->right)
        dfs(root->right, res, result);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    string res;
    vector<string> result;
    if (root == nullptr)
        return result;
    dfs(root, res, result);
    return result;
}

/*
时间:20250813 10:28
226. 翻转二叉树
已解答
简单
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/
// 相当于前序遍历
TreeNode *invertTree(TreeNode *root)
{

    if (root == nullptr)
        return root;
    if (!root->left && !root->right)
        return root;
    if (root->left || root->right)
    {
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
    }
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
// };

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
