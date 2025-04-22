/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root) return{};
        queue<TreeNode*> que; 
        que.push(root);
        while (!que.empty())
        {
            double sum = 0;
            int size = que.size();
            for(int i = 0;i<size;i++)
            {
                TreeNode* node = que.front(); 
                sum += que.front()->val;
                que.pop();
                if(node->left) que.push(node->left); 
                if(node->right) que.push(node->right); 
            }
            result.push_back(sum/size);
        }
        return result; 
    }
};
// @lc code=end

