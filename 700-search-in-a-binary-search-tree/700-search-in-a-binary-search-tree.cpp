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
    void solver(TreeNode* root,int target,TreeNode* &sub)
    {
        if(!root)
        {
            return;
        }
        if(root->val==target)
        {
            sub=root;
            return;
        }
        
        solver(root->left,target,sub);
        solver(root->right,target,sub);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *sub = NULL;
        solver(root,val,sub);
        return sub;
    }
};