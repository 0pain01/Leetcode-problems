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
    
    void helper(TreeNode* root , int targetSum,int *flag,int sum)
    {
        if(!root)
            return;
        sum+= root->val;
    
        if(sum==targetSum && root->left==NULL && root->right==NULL)
            *flag=1;
        helper(root->left,targetSum,flag,sum);
        helper(root->right,targetSum,flag,sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int flag =0;
        int sum=0;
        helper(root,targetSum,&flag,sum);
        
        if(flag==1)
            return true;
        else
            return false;
    }
};