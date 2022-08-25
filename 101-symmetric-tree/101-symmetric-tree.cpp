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
    bool solver(TreeNode* x ,TreeNode* y)
    {
        if(!x || !y){
            return x==y;
        }
        
        return x->val==y->val and solver(x->left,y->right) and (solver(x->right,y->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return solver(root->left,root->right);
    }
};