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
    vector <int> pre (TreeNode* root, vector<int> &h){
        if(root)
        {
            h.push_back(root->val);
            pre(root->left,h);
            pre(root->right,h);
        }
        return h;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> h ;
        h=pre(root,h);
        
        return h;
    }
};