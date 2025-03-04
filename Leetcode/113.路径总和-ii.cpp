/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int> out;
        helper(root,targetSum,out,res);
        return res;
    }
    void helper(TreeNode*node,int sum,vector<int>&out,vector<vector<int>>&res)
    {
        if (!node)
        {
            return ;
        }
        out.push_back(node->val);
        if (sum == node->val&&!node->left&&!node->right)
        {
            res.push_back(out);
        }
        helper(node->left,sum-node->val,out,res);
        helper(node->right,sum-node->val,out,res);
        out.pop_back();
    }
};
// @lc code=end

