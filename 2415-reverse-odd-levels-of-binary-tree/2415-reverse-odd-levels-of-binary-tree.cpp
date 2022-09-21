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
    void solver(TreeNode *l,TreeNode *r,int lev)
    {
        
        if(lev%2==0)
            swap(l->val,r->val);
        
        if(!l->right and !l->left)return;
        if(!r->right and !r->left)return;
        
        solver(l->left,r->right,lev+1);
        solver(l->right,r->left,lev+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        int l =0;
        if(!root  or !root->left or !root->right)return root;
        solver(root->left,root->right,l);
        return root;
    }
};