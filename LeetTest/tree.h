#include<iostream>
#include <vector>
#include<stdio.h>
// 链式存储二叉树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Tree
{
private:
    /* data */
    TreeNode* head;
public:
    Tree();
    Tree(TreeNode*curr,int * value,int num);
    ~Tree();
};

Tree::Tree():head(nullptr)
{
}
Tree::Tree(TreeNode*curr, int * value, int num):head(nullptr)
{
    if(num = 0)
        return;
    
    curr->val = value[0];
    Tree(curr->left,++value,--num);
    Tree(curr->right,++value,--num);
}
Tree::~Tree()
{
}


/*
    递归:
    1.确定参数和返回值
    2.确定终止条件
    3.确定单层递归逻辑 
*/
// 前序遍历--中左右
void pretraversal(TreeNode* tree,std::vector<int> &vec)
{
    if(tree==nullptr)
        return;
    vec.push_back(tree->val);    
    pretraversal(tree->left,vec);    
    pretraversal(tree->right,vec);    
}
std::vector<int> preordertraversal(TreeNode* treeroot)
{
    std::vector<int> result; 
    pretraversal(treeroot,result);
    return result;    
}

// 中序遍历--左中右
void midtraversal(TreeNode* tree,std::vector<int> &vec)
{
    if(tree == nullptr)
        return;
    midtraversal(tree->left,vec);
    vec.push_back(tree->val);
    midtraversal(tree->right,vec);
}
std::vector<int> midordertraversal(TreeNode* treeroot)
{
    std::vector<int> result;
    midtraversal(treeroot,result);
    return result;
}

// 后序遍历 -- 左右中
void latetraversal(TreeNode* tree,std::vector<int> &vec)
{
    if(tree == nullptr)
        return;
    latetraversal(tree->left,vec);
    latetraversal(tree->right,vec);
    vec.push_back(tree->val);
}
std::vector<int> lateordertraversal(TreeNode* treeroot)
{
    std::vector<int> result;
    midtraversal(treeroot,result);
    return result;
}








