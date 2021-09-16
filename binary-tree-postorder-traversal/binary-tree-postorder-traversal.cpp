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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector <int> v;
        stack <TreeNode*> s;
        struct TreeNode* prev=NULL;
        
        do{
            while(root){
                s.push(root);
                root=root->left;  
            }
            
            while(!root && !s.empty()){
                root=s.top();
                if(root->right==NULL || root->right==prev){
                    v.push_back(root->val);
                    s.pop();
                    prev=root;
                    root=NULL;
                }
                else
                    root=root->right;
                
            }
            
        }while(!s.empty());
        
        return v;
    }
};