// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
private:
    vector<int>vec;
    void midtrversal(TreeNode* root)
    {
        if(!root) return ;
        midtrversal(root->left);
        vec.push_back(root->val);
        midtrversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
       midtrversal(root);
       int temp = abs(vec[0]-vec[1]);
       for(int i = 1;i<vec.size()-1;i++)
       {
        if(abs(vec[i]-vec[i+1])<temp)
        {
            temp = abs(vec[i]-vec[i+1]);
        }
       }
       return temp;
    }
};
// @lc code=end

