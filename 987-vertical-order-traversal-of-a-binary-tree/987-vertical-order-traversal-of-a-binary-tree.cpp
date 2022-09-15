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
    void trav(TreeNode*root,map<int,map<int,vector<int>>>&mp,int x,int y)
    {
        if(root==NULL)
            return;
        mp[x][y].push_back(root->val);
        trav(root->left,mp,x-1,y+1);
        trav(root->right,mp,x+1,y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        vector<vector<int>>res;
        trav(root,mp,0,0);
        for(auto i:mp)
        {
            vector<int>ans;
            for(auto j:mp[i.first])
            {
                vector<int>arr;
                for(auto it:mp[i.first][j.first])
                {
                    arr.push_back(it);
                } 
                sort(arr.begin(),arr.end());
                ans.insert(ans.end(),arr.begin(),arr.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};