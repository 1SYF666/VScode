// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem257.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str = "";
        binaryTreePaths1(root,str,result);
        return result;
    }
    void binaryTreePaths1(TreeNode* root,string str, vector<string>& result)
    {
        if(!root) 
        {
            return ;
        }
        if(!root->left&&!root->right)
        {
            str+=to_string(root->val);
            result.push_back(str);
            return;
        }

        str+=to_string(root->val); // 中
        //左
        binaryTreePaths1(root->left,str+"->",result);
        //右
        binaryTreePaths1(root->right,str+"->",result);
    }
};
// @lc code=end

