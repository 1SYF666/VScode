/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return{};
        int depth = 0;
        vector<vector<int>> ves;
        vector<int> result;
        levelOrder1(root,depth,ves);
        for (int i = 0; i < ves.size(); i++)
        {
            result.push_back(ves[i][ves[i].size()-1]);
        }
        
        return result;
    }

    void levelOrder1(TreeNode* root,int depth,vector<vector<int>>& ves)
    {
        if(!root) return;
        if(ves.size()==depth)
            ves.push_back(vector<int>());
        // 入
        ves[depth++].push_back(root->val);  
        // 出
        levelOrder1(root->left,depth,ves);
        levelOrder1(root->right,depth,ves);
    }

};
// @lc code=end

