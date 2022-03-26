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
    bool solver(TreeNode* l,TreeNode *r)
    {
        if(!l && !r)
            return true;
        
        if((!l&&r) || (l&&!r))
            return false;
        
        if(l->val!=r->val)
            return false;
        
        return solver(l->left,r->right) && solver(l->right,r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solver(root->left,root->right);
    }
};