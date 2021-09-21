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
    
    int getDiameter(TreeNode *root, int &diameter)
    {
       if(!root) return 0;

        int l = getDiameter(root->left, diameter);
        int r = getDiameter(root->right, diameter);

        int max_diameter = l + r;

        diameter = max(diameter, max_diameter);

        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        
        getDiameter(root,diameter);
        
        return diameter;
    }
};