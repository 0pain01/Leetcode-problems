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
    void solver(TreeNode *&a,TreeNode *&b)
    {
        if(a==NULL and b==NULL)
            return;
        swap(a,b);
        if(a!=NULL)
            solver(a->left,a->right);
        if(b!=NULL)
        solver(b->left,b->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        solver(root->left,root->right);
        return root;
    }
};