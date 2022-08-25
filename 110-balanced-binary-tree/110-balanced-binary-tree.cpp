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
        if(l==-1 || r==-1)
        {
            return -1;
        }
        if(abs(l-r)>1)
            return -1;
        return max(l,r)+1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        int k=height(root);
        if(k==-1)
            return false;
        return true;
    }
};