/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            TreeNode* node;
            for(int i = 0;i<size;i++)
            {
                node = que.front();
                que.pop();
                swap(node->left,node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
    void invertTree1(TreeNode* root)
    {
        if(!root) return;
        TreeNode* node;
        node = root->left;
        root->left = root->right;
        root->right = node;
        if(root->left)invertTree1(root->left);
        if(root->right)invertTree1(root->right);
    }
    
};
// @lc code=end

