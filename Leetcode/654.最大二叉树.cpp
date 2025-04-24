/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int start = 0;
        int end = nums.size()-1;
        return MaximumBinaryTree(nums,start,end);
    }
    TreeNode*MaximumBinaryTree(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return nullptr;
        TreeNode* root = new TreeNode(0);
        // 找最值
        int left = start;
        int right = end;
        int rootindex = left;
        while (left<right)
        {
            if(nums[left]<nums[right])
            {
                rootindex = right;
                left++;
            }
            else
            {
                rootindex = left;
                right--;
            }
        }
        root->val = nums[rootindex];

        root->left = MaximumBinaryTree(nums,start,rootindex-1);
        root->right = MaximumBinaryTree(nums,rootindex+1,end);
        return root;
    }

};
// @lc code=end

