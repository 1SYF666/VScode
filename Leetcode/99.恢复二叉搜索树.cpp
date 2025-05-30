/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int>vals;
        inorder(root,list,vals);
        sort(vals.begin(),vals.end());
        for (int i = 0; i < list.size(); ++i)
        {
            list[i]->val = vals[i];
        }
    }

    void inorder(TreeNode* root,vector<TreeNode*>& list,vector<int>& vals)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left,list,vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right,list,vals);
    }

    

};
// @lc code=end

