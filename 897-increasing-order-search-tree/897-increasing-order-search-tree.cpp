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
    vector<int>arr;
    TreeNode *ans=NULL,*temp=NULL;
    void solver(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        solver(root->left);
    
        if(ans==NULL)
        {
            ans = new TreeNode(root->val);
            temp=ans;
        }
        else
        {
            temp->right = new TreeNode(root->val);
            temp=temp->right;
        }
            
        solver(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        solver(root);
        return ans;
    }
};