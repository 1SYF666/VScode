/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val>val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        else 
        {
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};
// @lc code=end

