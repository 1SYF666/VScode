#include <vector>
#include <unordered_map>
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
501. 二叉搜索树中的众数
已解答
简单
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
*/
void searchBST(TreeNode *cur, unordered_map<int, int> &map)
{
    if (cur == nullptr)
        return;
    map[cur->val]++;
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return;
}
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
vector<int> findMode(TreeNode *root)
{
    unordered_map<int, int> map;
    vector<int> result;
    if (root == nullptr)
        return result;
    searchBST(root, map);

    vector<pair<int, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), cmp);
    result.push_back(vec[0].first);
    for (int i = 1; i < vec.size(); i++)
    {
        // 取最高的放到数组中
        if (vec[i].second == vec[0].second)
            result.push_back(vec[i].first);
        else
            break;
    }
    return result;
}

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
//     TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
// };

/*
时间:20250815 15:47
106. 从中序与后序遍历序列构造二叉树
已解答
中等
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
*/

TreeNode *tree(vector<int> &inorder, vector<int> &postorder)
{
    // 第一步
    if (postorder.size() == 0)
        return nullptr;

    // 第二步
    int rootvalue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootvalue);

    // 叶子节点
    if (postorder.size() == 1)
        return root;

    // 第三步：找切割点
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
    {
        if (inorder[delimiterIndex] == rootvalue)
            break;
    }
    // 第四步
    //                   [0,delimiterindex)    [delimiterIndex+1,end];
    // 切割中序数组，得到 中序左数组(左子树)和中序右数组(右)

    vector<int> leftinorder(delimiterIndex, 0);
    for (int i = 0; i < delimiterIndex; i++)
    {
        leftinorder[i] = inorder[i];
    }
    vector<int> rightinorder(inorder.size() - delimiterIndex - 1, 0);
    for (int i = delimiterIndex + 1; i < inorder.size(); i++)
    {
        rightinorder[i - delimiterIndex - 1] = inorder[i];
    }
    //                   [0,delimiterindex) [delimiterindex,end-1]
    // 切割后序数组，得到 后序左数组(左子树)和后序右数组（右）
    vector<int> leftpostorder(delimiterIndex, 0);
    for (int i = 0; i < delimiterIndex; i++)
    {
        leftpostorder[i] = postorder[i];
    }
    vector<int> rightpostorder(inorder.size() - delimiterIndex - 1, 0);
    for (int i = delimiterIndex; i < postorder.size() - 1; i++)
    {
        rightpostorder[i - delimiterIndex] = postorder[i];
    }

    // 第五步
    root->left = tree(leftinorder, leftpostorder);
    root->right = tree(rightinorder, rightpostorder);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return tree(inorder, postorder);
}
