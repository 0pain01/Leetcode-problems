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
        if(!l and !r)return;
        if(lev%2!=0)
            swap(l->val,r->val);
        
        solver(l->left,r->right,lev+1);
        solver(l->right,r->left,lev+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lev =1;
        solver(root->left,root->right,lev);
        return root;
    }
};