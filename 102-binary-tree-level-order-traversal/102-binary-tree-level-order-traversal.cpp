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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> arr;
        
        vector<int> x;
        queue <TreeNode*> q;
        if(root==NULL)
            return arr;
        
        q.push(root);
        q.push(NULL);
        x.push_back(root->val);
        arr.push_back(x);
        
        x.clear();
        int cnt=0;
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root!=NULL)
            {
                if(root->left)
                    q.push(root->left),x.push_back(root->left->val);
                if(root->right)
                    q.push(root->right),x.push_back(root->right->val);
            }
            else if(!q.empty())
            {
                arr.push_back(x);
                x.clear();
                q.push(NULL);
                cnt++;
            }
        }
        
        return arr;
    }
};