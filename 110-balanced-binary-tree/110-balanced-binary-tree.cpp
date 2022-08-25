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
    int height(TreeNode *node)
    {
        if(node==NULL)
            return 0;
        
        int l = height(node->left);
        int r = height(node->right);
     
        return max(l,r)+1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        int x = height(root->left);
        int y = height(root->right);
        
        if(abs(x-y)>1)
            return false;
        else true;
        
        return isBalanced(root->left) and isBalanced(root->right);

    }
};