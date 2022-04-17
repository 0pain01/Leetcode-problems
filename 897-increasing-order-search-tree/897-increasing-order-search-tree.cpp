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
    void solver(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        solver(root->left);
        arr.push_back(root->val);
        solver(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        solver(root);

        TreeNode *newR = new TreeNode(arr[0]);
        TreeNode *ans=newR;
        
        for(int i=1;i<arr.size();i++)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            newR->right=temp;
            newR=temp;
        }
        
        return ans;
    }
};