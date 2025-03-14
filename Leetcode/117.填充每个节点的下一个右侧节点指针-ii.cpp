/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* p  = root->next;
        while (p)
        {
            if (p->left)
            {
                p=p->left;
                break;
            }
            if (p->right)
            {
                p=p->right;
                break;
            }
            p=p->next;
        }

        if (root->right)
        {
            root->right->next = p;
        }
        
        if (root->left)
        {
            root ->left->next = root->right?root->right:p;
        }

        connect(root->right);
        connect(root->left);

        return root;
    }
};
// @lc code=end

