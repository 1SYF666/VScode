/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
 */#include <climits>  // For LONG_MIN and LONG_MAX
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root,long mn,long mx)
    {
        if (!root)
        {
            return true;
        }
        if (root->val<=mn||root->val>=mx)
        {
            return false;
        }
        return isValidBST(root->left,mn,root->val)&&isValidBST(root->right,root->val,mx);   
    }
};
// @lc code=end

