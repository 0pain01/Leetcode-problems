/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pre(TreeNode* root,map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL)
            return;
        
        if(root->left) 
        {
            mp[root->left]=root;
            pre(root->left,mp);
        }
        if(root->right) 
        {
            mp[root->right]=root;
            pre(root->right,mp);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        map<TreeNode*,bool>vis;
        pre(root,mp);
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        
        while(!q.empty())
        {
            auto x = q.front();
            vis[x.first]=true;
            q.pop();
            
            if(x.second==k)
            {
                ans.push_back(x.first->val);
            }
            else
            {
                if(x.first->left and vis[x.first->left]==false)
                {
                    q.push({x.first->left,x.second+1});
                }
                if(x.first->right and vis[x.first->right]==false)
                {
                    q.push({x.first->right,x.second+1});
                }
                if(mp.find(x.first)!=mp.end() and vis[mp[x.first]]==false)
                {
                    q.push({mp[x.first],x.second+1});
                }
            }
            
        }
        return ans;
        
    }
};