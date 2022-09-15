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
    void trav(TreeNode*root,map<int,map<int,multiset<int>>>&mp,int x,int y)
    {
        if(root==NULL)
            return;
        mp[x][y].insert(root->val);
        trav(root->left,mp,x-1,y+1);
        trav(root->right,mp,x+1,y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>res;
        trav(root,mp,0,0);
        for(auto i:mp)
        {
            vector<int>ans;
            for(auto j:mp[i.first])
            {

                for(auto it:mp[i.first][j.first])
                {
                    ans.push_back(it);
                } 
            }
            res.push_back(ans);
        }
        return res;
    }
};