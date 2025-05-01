/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        // 迭代法 右中左
        if(!root) return nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = new TreeNode(0);
        cur = root;
        while (!st.empty()||cur)
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = st.top();
                st.pop();
                cur->val += sum;
                sum = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
};
// @lc code=end

