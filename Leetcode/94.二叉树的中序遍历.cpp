// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode * root,vector<int>& res)
    {
        if (!root)
        {
            return ;
        }
        if (root->left)
        {
            inorder(root->left,res);
        }
        res.push_back(root->val);
        if (root->right)
        {
            inorder(root->right,res);
        }
    }
};
// @lc code=end

