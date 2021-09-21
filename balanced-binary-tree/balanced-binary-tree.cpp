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
    int height(TreeNode* root)
    {
        if(!root) return 0;
        
        int a = height(root->left);
        int b = height(root->right);
        
        return max(a,b)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;        
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r)<=1)
            return true;
        
    return false;
    }
};