/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q{{root}};
        int cnt = 0;
        
        while (!q.empty())
        {
            vector<int>onelevel;
            for (int i = q.size(); i >0; --i)
            {
                TreeNode* t = q.front();
                q.pop();
                onelevel.push_back(t->val);
                if (t->left)q.push(t->left);
                if (t->right)q.push(t->right);
            }
            if (cnt%2==1)reverse(onelevel.begin(),onelevel.end());
            res.push_back(onelevel);
            ++cnt;    
        }
        return res;
        
    }
};
// @lc code=end

